#include<exception>
#include<thread>
#include<memory>
#include<stack>
#include<mutex>
#include<condition_variable>
#include<future>

struct empty_stack : std::exception {
    const char* what() const throw();
};

template <typename T>
class threadsafe_stack {
private:
    std::stack<T> data;
    mutable std::mutex mut;
public:
    threadsafe_stack() {}
    threadsafe_stack(const threadsafe_stack& other) {
        std::lock_guard<std::mutex> lk(other.mut);
        data = other.data;
    }
    threadsafe_stack& operator=(const threadsafe_stack&) = delete;

    void push(T new_value) {
        std::lock_guard<std::mutex> lk(mut);
        data.push(std::move(new_value));
    }
    std::shared_ptr<T> pop() {
        std::lock_guard<std::mutex> lk(mut);
        if (data.empty())
            throw empty_stack();
        std::shared_ptr<T> const res(std::make_shared<T>(std::move(data.top())));
        data.pop();
        return res;
    }
    void pop(T& value) {
        std::lock_guard<std::mutex> lk(mut);
        if (data.empty())
            throw empty_stack();
        value = std::move(data.top());
        data.pop();
    }
    bool empty() const {
        std::lock_guard<std::mutex> lk(mut);
        return data.empty();
    }
};