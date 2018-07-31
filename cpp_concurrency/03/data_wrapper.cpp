/* 3.2.2 为保护共享数据精心组织代码 */
#include<string>
#include<mutex>

class some_data {
    int a;
    std::string b;
public:
    void do_something();
};

class data_wrapper {
private:
    some_data data;
    std::mutex m;
public:
    template<typename Function>
    void process_data(Function func) {
        std::lock_guard<std::mutex> l(m); //传递受保护的数据到用户提供的函数
        func(data);
    }
};

some_data *unprotected;

void malicious_function(some_data &protected_data) {
    unprotected = &protected_data;
}

data_wrapper x;

void foo() {
    x.process_data(malicious_function); //传入一个恶意函数
    unprotected->do_something(); //对受保护的数据进行未受保护的访问
}