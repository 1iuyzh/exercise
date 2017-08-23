// Exercise 12.10:
// Explain whether the following call to the process function defined on page
// 464 is correct. If not, how would you correct the call?
// correct.

#include <iostream>
#include <memory>

void process(std::shared_ptr<int> ptr)
{
    std::cout << "inside the process function: " << ptr.use_count() << std::endl;
}

int main()
{
    std::shared_ptr<int> p(new int(42));
    // 创建一个临时变量, shared_ptr<int>(p), 在赋值形参后被销毁
    process(std::shared_ptr<int>(p));
    // 函数调用结束后, 函数内的ptr被销毁, use_count()返回1

    // codes below shows how the reference count change.
    std::cout << p.use_count() << std::endl;
    auto q = p;
    std::cout << p.use_count() << std::endl;
    std::cout << "the int p now points to is: " << *p << std::endl;
    return 0;
}