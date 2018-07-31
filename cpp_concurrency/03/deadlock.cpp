/* 3.2.4 死锁 */
#include<mutex>

class some_big_object {
};
void swap(some_big_object &lhs, some_big_object &rhs);

class X {
private:
    some_big_object some_detail;
    std::mutex m;
public:
    X(const some_big_object &sd) : some_detail(sd) {}
    friend void swap(X &lhs, X &rhs) {
        if (&lhs == &rhs)
            return;
        std::lock(lhs.m, rhs.m);
        std::lock_guard<std::mutex> lock_a(lhs.m, std::adopt_lock); //adopt_lock告知lock_guard对象互斥元已被锁
        std::lock_guard<std::mutex> lock_b(rhs.m, std::adopt_lock);
        swap(lhs.some_detail, rhs.some_detail);
    }
};