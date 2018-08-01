/* 4.2.2 将任务与future相关联 */
#include<string>
#include<vector>
#include<future>
#include<queue>
#include<mutex>
#include<thread>
#include<utility>

template <typename Function>
class packaged_task {
};

// 特例化
template<>
class packaged_task<std::string (std::vector<char>*, int)> {
    public:
    template <typename Callable>
    explicit packaged_task(Callable &&f); //模板参数推断
    std::future<std::string> get_future();
    void operator() (std::vector<char>*, int);
};

// 使用std::packaged_task在GUI线程上运行代码
std::mutex m;
std::queue<std::packaged_task<void()>> tasks;

bool gui_shutdown_message_received();
void get_and_process_gui_message();

void gui_thread() {
    while (!gui_shutdown_message_received()) {
        get_and_process_gui_message();
        std::packaged_task<void()> task;
        {
            std::lock_guard<std::mutex> lk(m);
            if (tasks.empty())
                continue;
            task = std::move(tasks.front());
            tasks.pop(); //pop_front
        }
        task();
    }
}

std::thread gui_bg_thread(gui_thread);

template <typename Func>
std::future<void> post_task_for_gui_thread(Func f) {
    std::packaged_task<void()> task(f);
    std::future<void> res = task.get_future();
    std::lock_guard<std::mutex> lk(m);
    tasks.push_back(std::move(task));
    return res;
}