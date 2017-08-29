#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector;

// 类值
// swap()
class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) { }
    HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) { }
    HasPtr(HasPtr&&) noexcept;   // 移动构造函数
    HasPtr& operator=(const HasPtr&);
    HasPtr& operator=(HasPtr&&) noexcept;   // 移动赋值运算符
    HasPtr& operator=(HasPtr);  /// 拷贝并交换
    ~HasPtr() { delete ps; }
    void swap(HasPtr&);

private:
    string *ps;
    int i;
};
inline void swap(HasPtr &lhs, HasPtr &rhs) {
    lhs.swap(rhs);
}
void HasPtr::swap(HasPtr &rhs) {
    using std::swap;
    swap(ps, rhs.ps);
    swap(i, rhs.i);
    cout << "call swap()" << endl;
}
HasPtr::HasPtr(HasPtr &&rhs) noexcept : ps(rhs.ps), i(rhs.i) {
    rhs.ps = nullptr;
}
HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    auto newp = new string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
}
HasPtr& HasPtr::operator=(HasPtr &&rhs) noexcept {
    if (this != &rhs) {
        ps = rhs.ps;
        i = rhs.i;
        rhs.ps = nullptr;
    }
    return *this;
}
HasPtr& HasPtr::operator=(HasPtr rhs) {
    this->swap(rhs);
    return *this;
}

int main() {
    return 0;
}
