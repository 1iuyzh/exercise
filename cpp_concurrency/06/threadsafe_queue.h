#include<queue>
#include<condition_variable>
#include<mutex>
#include<thread>
#include<memory>

template <typename T>
class threadsafe_queue {
private:
    mutable std::mutex mut;
    std::queue<T> data;
    std::condition_variable data_cond;
public:
    threadsafe_queue() {}

    void push(T new_value) {
        std::lock_guard<std::mutex> lk(mut);
        data.push(std::move(data.front()));
        data_cond.notify_one();
    }
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data.empty();});
        value = std::move(data.front());
        data.pop();
    }
    std::shared_ptr<T> wait_and_pop() {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data.empty();});
        std::shared_ptr<T> res(
            std::make_shared<T>(std::move(data.front())));
        data.pop();
        return res;
    }
    bool try_pop(T& value) {
        std::lock_guard<std::mutex> lk(mut);
        if (data.empty())
            return false;
        value = std::move(data.front());
        data.pop();
        return true;
    }
    std::shared_ptr<T> try_pop() {
        std::lock_guard<std::mutex> lk(mut);
        if (data.empty())
            return false;
        std::shared_ptr<T> res(
            std::make_shared<T>(std::move(data.front())));
        data.pop();
        return res;
    }
    bool empty() const {
        std::lock_guard<std::mutex> lk(mut);
        return data.empty();
    }
};