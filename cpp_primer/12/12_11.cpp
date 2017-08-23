#include<iostream>
#include<memory>

using std::cin; using std::cout; using std::endl;
using std::shared_ptr;

void process(shared_ptr<int> ptr) {
    std::cout << "inside the process function: " << ptr.use_count() << std::endl;
}

int main() {
    shared_ptr<int> p(new int (42));
    // p.get()返回指向*p的普通指针
    // 由普通指针p.get()创建新的智能指针
    // 新的智能指针和p分开独立计数
    // 新的智能指针在赋值形参后被摧毁, 在函数内部use_count()的结果应该为1
    // 函数调用结束后, ptr被摧毁，由于ptr是最后一个指向动态内存的智能指针, 内存也被释放
    // p和ptr指向相同的内存, 由于内存被ptr释放, 调用p出现错误
    process(shared_ptr<int>(p.get()));

    // error, p指向的内存被释放
    // cout << p.use_count() << endl;
    // cout << "the int p now points to is: " << *p << endl;
    return 0;
}