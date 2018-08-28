#include<functional>
#include<atomic>
#include<thread>
#include<future>
#include<type_traits>
#include"threadsafe_queue.h"
#include"join_threads.h"

//std::function<>要求存储的函数对象是可以拷贝和构造的, 而std::packaged_task<>只是可移动的
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

class thread_pool {
    std::atomic_bool done;
    threadsafe_queue<function_wrapper> work_queue; //线程安全队列管理待处理任务
    std::vector<std::thread> threads; //使用vector保存工作线程
    join_threads joiner; //保证线程池被销毁前所有线程已完成

    //调用等待队列中的任务
    void worker_thread() {
        while(!done) {
            function_wrapper task;
            if (work_queue.try_pop(task))
                task();
            else
                std::this_thread::yield(); //暂停一小段时间
        }
    }

public:
    thread_pool() : done(false), joiner(threads) {
        unsigned const thread_count = std::thread::hardware_concurrency(); //并发线程数量
        try {
            for (unsigned i = 0; i < thread_count; ++i) {
                threads.push_back(
                    std::thread(&thread_pool::worker_thread, this));
            }
        }
        catch (...) {
            done = true; //出现异常设置done标志
            throw;
        }
    }

    ~thread_pool() {
        done = true;
    }

    //将可调用对象包装成std::function<void()>实例, 放到待处理任务队列中
    template<typename FunctionType>
    std::future<typename std::result_of<FunctionType()>::type> submit(FunctionType f) {
        typedef typename std::result_of<FunctionType()>::type result_type;
        std::packaged_task<result_type()> task(std::move(f));
        std::future<result_type> res(task.get_future()); //保存任务的返回值
        work_queue.push(std::move(task));
        return res;
    }
};