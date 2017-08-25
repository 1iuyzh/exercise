#include<iostream>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::string;

// 类指针
class HasPtr {
public:
    // 构造函数, 申请动态空间存储引用计数, 并置1
    HasPtr(const string &s = string()) : ps(new string(s)), i(0), pi(new int(1)) { }
    // 拷贝构造函数, 拷贝指针本身, 引用计数+1
    HasPtr(const HasPtr &hp) : ps(hp.ps), i(hp.i), pi(hp.pi) { ++*pi; }
    // 拷贝赋值运算符, 左侧引用计数-1, 右侧引用计数+1, 如果为0记得释放
    HasPtr& operator=(const HasPtr &rhs) {
        // 类指针, 而不是类值
        ++*rhs.pi;
        if (--*pi == 0) {
            delete ps;
            delete pi;
        }
        ps = rhs.ps;
        i = rhs.i;
        pi = rhs.pi;
        return *this;
    }
    ~HasPtr() {
        if (--*pi == 0) {
            delete pi;
            delete ps;
        }
    }
private:
    string *ps;
    int i;
    int *pi;
};

int main() {
    // test
    return 0;
}