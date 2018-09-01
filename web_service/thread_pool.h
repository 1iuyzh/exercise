#include"threadsafe_queue.h"
#include<thread>
#include<mutex>
#include<future>
#include<atomic>
#include<vector>
#include<list>
#include<queue>
#include<deque>
#include<type_traits>
#include<functional>
#include<memory>
#include<condition_variable>
#include<algorithm>

//对象不允许拷贝只允许移动
class function_wrapper {
    struct impl_base {
        virtual void call() = 0; //纯虚函数
        virtual ~impl_base() {}
    };

    std::unique_ptr<impl_base> impl;

    template<typename F>
    struct impl_type : impl_base {
        F f;
        impl_type(F&& f_) : f(std::move(f_)) {}
        void call() { f(); }
    };

public:
    template<typename F>
    function_wrapper(F&& f) : impl(new impl_type<F>(std::move(f)))
    {}

    void operator() () {
        impl->call();
    }

    function_wrapper() = default;
    
    function_wrapper(function_wrapper&& other) :
        impl(std::move(other.impl))
    {}

    function_wrapper& operator=(function_wrapper&& other) {
        impl = std::move(other.impl);
        return *this;
    }

    function_wrapper(const function_wrapper&) = delete;
    function_wrapper(function_wrapper&) = delete;
    function_wrapper& operator=(const function_wrapper&) = delete;
};

//允许任务窃取队列
class work_stealing_queue {
private:
    typedef function_wrapper data_type;
    std::deque<data_type> the_queue;
    mutable std::mutex the_mutex;

public:
    work_stealing_queue()
    {}

    work_stealing_queue(const work_stealing_queue& other) = delete;
    work_stealing_queue& operator=(
        const work_stealing_queue& other) = delete;
    
    void push(data_type data) {
        std::lock_guard<std::mutex> lock(the_mutex);
        the_queue.push_front(std::move(data));
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(the_mutex);
        return the_queue.empty();
    }

    bool try_pop(data_type& res) {
        std::lock_guard<std::mutex> lock(the_mutex);
        if (the_queue.empty())
            return false;
        res = std::move(the_queue.front());
        the_queue.pop_front();
        return true;
    }

    bool try_steal(data_type& res) {
        std::lock_guard<std::mutex> lock(the_mutex);
        if (the_queue.empty())
            return false;
        res = std::move(the_queue.back()); //最小化竞争
        the_queue.pop_back();
        return true;
    }
};

class join_threads {
    std::vector<std::thread>& threads;

public:
    explicit join_threads(std::vector<std::thread>& threads_) :
        threads(threads_) {}

    ~join_threads() {
        for (unsigned long i = 0; i < threads.size(); i++) {
            if (threads[i].joinable())
                threads[i].join();
        }
    }
};

class thread_pool {
    static thread_local work_stealing_queue* local_work_queue;
    static thread_local unsigned my_index;

    typedef function_wrapper task_type;

    std::atomic_bool done;
    threadsafe_queue<task_type> pool_work_queue; //全局任务队列
    std::vector<std::unique_ptr<work_stealing_queue>> queues; //局部任务队列
    std::vector<std::thread> threads; //工作线程
    join_threads joiner; //保证线程池被销毁前完成所有工作线程

    void worker_thread(unsigned my_index_) {
        //my_index = my_index_;
        //local_work_queue = queues[my_index].get();
        while (!done) //循环
            run_pending_task();
    }

    bool pop_task_from_local_queue(task_type& task) {
        return local_work_queue && local_work_queue->try_pop(task);
    }

    bool pop_task_from_pool_queue(task_type& task) {
        return pool_work_queue.try_pop(task);
    }

    bool pop_task_from_other_thread_queue(task_type& task) {
        for (unsigned i = 0; i < queues.size(); i++) {
            unsigned const index = (my_index + i + 1) % queues.size();
            if (queues[index]->try_steal(task))
                return true;
            return false;
        }
    }

public:
    thread_pool() : joiner(threads), done(false) {
        unsigned const thread_count = std::thread::hardware_concurrency(); //并发线程数量
        try {
            for (unsigned i = 0; i < thread_count; ++i) {
                queues.push_back(std::unique_ptr<work_stealing_queue>(
                    new work_stealing_queue));
                threads.push_back(
                    std::thread(&thread_pool::worker_thread, this, i)); //this
            }
        }
        catch (...) {
            done = true; //设置done标志
            throw;
        }
    }

    ~thread_pool() {
        done = true;
    }

    template<typename FunctionType>
    std::future<typename std::result_of<FunctionType()>::type> submit(FunctionType f) {
        typedef typename std::result_of<FunctionType()>::type result_type;
        std::packaged_task<result_type()> task(f);
        std::future<result_type> res(task.get_future()); //保存任务的返回值
        /*
        if (local_work_queue)
            local_work_queue->push(std::move(task));
        else
        */
            pool_work_queue.push(std::move(task));
        return res;
    }

    void run_pending_task() {
        function_wrapper task;
        //pop_task_from_local_queue(task) || pop_task_from_other_thread_queue(task)
        if (pop_task_from_pool_queue(task)) {
            task();
        }
        else
            std::this_thread::yield();
    }
};