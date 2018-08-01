/* 4.2.1 从后台任务中返回值 */
#include<future>
#include<iostream>
#include<string>
#include<functional>

struct X {
    void foo(int, std::string const&);
    std::string bar(std::string const&);
};
X x;
auto f1 = std::async(&X::foo, &x, 42, "Hello"); //调用p->foo(42, "Hello"), 其中p是&x
auto f2 = std::async(&X::bar, x, "goodbye"); //调用tmpx.bar("goodbye"), 其中tmpx是x的副本

struct Y {
    double operator() (double);
};
Y y;
auto f3 = std::async(Y(), 3.141); //调用tmpy(3.141), 其中tmpy是从Y()移动构造的
auto f4 = std::async(std::ref(y), 2.718); //调用y(2.718)

X baz(X&);
auto f5 = std::async(baz, std::ref(x)); //调用baz(x)

int find_the_answer_to_ltuae();
void do_other_stuff();

int main() {
    std::future<int> the_answer = std::async(find_the_answer_to_ltuae);
    do_other_stuff();
    std::cout << "The answer is" << the_answer.get() << std::endl;
    return 0;
}