/* 3.2.3 发现接口中固有的竞争条件 */
#include<exception>
#include<memory>
#include<mutex>
#include<stack>

struct empty_stack: std::exception {
    const char* what() const throw(); //这个函数不抛出异常
};

template<typename T>
class threadsafe_stack {
private:
    std::stack<T> data;
    mutable std::mutex m;
public:
    threadsafe_stack();
    threadsafe_stack(const threadsafe_stack &other) {
        std::lock_guard<std::mutex> lock(other.m);
        data = other.data;
    }
    threadsafe_stack& operator=(const threadsafe_stack&) = delete;

    void push(T new_value) {
        std::lock_guard<std::mutex> lock(m);
        data.push(new_value);
    }
    // 返回指向出栈顶的指针
    std::shared_ptr<T> pop() {
        std::lock_guard<std::mutex> lock(m);
        if (data.empty())
            throw empty_stack();
        const std::shared_ptr<T> res(std::make_shared<T>(data.top()));
        data.pop();
        return res;
    }
    // 把希望接受出栈值的变量的引用, 作为参数传递给对pop()的调用
    void pop(T& value) {
        std::lock<std::mutex> lock(m);
        if (data.empty())
            throw empty_stack();
        value = data.top();
        data.pop();
    }
    bool empty() const {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};

int main() {
    return 0;
}