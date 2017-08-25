#include<iostream>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::string;

class HasPtr {
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) { }
    HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) { }
    HasPtr& operator=(const HasPtr &rhs) {
        // 由于是赋值操作, 肯定有动态空间需要释放
        delete ps;
        ps = new string(*rhs.ps);
        i = rhs.i;
        return *this;
    }
    ~HasPtr() {
        delete ps;
    }
// private:
    string *ps;
    int i;
private:
};

int main() {
    HasPtr a("Alpha");
    HasPtr b = a;
    HasPtr c;
    cout << *a.ps << endl;
    cout << *b.ps << endl;
    cout << *c.ps << endl;
    c = HasPtr("Delta");
    cout << *c.ps << endl;
    return 0;
}