/* 延迟初始化 */
#include<mutex>
#include<memory>

class some_resource {
public:
    void do_something();
};

std::shared_ptr<some_resource> resource_ptr;
std::mutex resource_mutex;

void foo1() {
    std::unique_lock<std::mutex> lk(resource_mutex);
    if (!resource_ptr) {
        resource_ptr.reset(new some_resource);
    }
    lk.unlock();
    resource_ptr->do_something();
}

/* call_once */
std::shared_ptr<some_resource> resource_ptr;
std::once_flag resource_flag;

void init_resource() {
    resource_ptr.reset(new some_resource);
}

void foo2() {
    std::call_once(resource_flag, init_resource);
    resource_ptr->do_something();
}