#ifndef cpp_13_30_h
#define cpp_13_30_h

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
    friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) { }
    HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) { }
    HasPtr& operator=(const HasPtr &rhs) {
        // 防自赋值出错
        auto newp = new string(*rhs.ps);
        delete ps;
        ps = newp;
        i = rhs.i;
        return *this;
    }
    ~HasPtr() {
        delete ps;
    }
    void swap(HasPtr &rhs) {
        using std::swap;
        swap(ps, rhs.ps);
        swap(i, rhs.i);
        cout << "call swap()" << endl;
    }
// private:
    string *ps;
    int i;
private:
};
inline
void swap(HasPtr &lhs, HasPtr &rhs) {
    lhs.swap(rhs);
}

#endif