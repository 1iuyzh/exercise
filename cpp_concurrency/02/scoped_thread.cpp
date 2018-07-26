#include<iostream>
#include<thread>

class scoped_thread {
    std::thread t;
public:
    explicit scoped_thread(std::thread &t_) : t(std::move(t_)) {
        if (!t.joinable())
            throw std::logic_error("No thread");
    }
    ~scoped_thread() {
        t.join();
    }
    scoped_thread(const scoped_thread&) = delete;
    scoped_thread& operator=(const scoped_thread&) = delete;
};

struct func {
    int &i;
    func(int &i_) : i(i_) {}
    void operator()() {
        for (unsigned j = 0; j < 10; ++j)
            std::cout << i;
    }
};

void f() {
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread t(my_func);
    scoped_thread s_t(t);
    for (unsigned j = 0; j < 10; ++j)
        std::cout << 1;
}

int main() {
    f();
    return 0;
}