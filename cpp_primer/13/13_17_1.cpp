#include<iostream>

using std::cin; using std::cout; using std::endl;

// 默认构造函数为每个对象生成一个唯一的序号
// 使用合成拷贝构造函数
class numbered {
public:
    friend void f(numbered s);
    numbered() : msyn(unique++) { }
private:
    static int unique;
    int msyn;
};

void f(numbered s) {
    cout << s.msyn << endl;
}

// 在所有函数之外定义并初始化静态成员
int numbered::unique = 0;

int main() {
    numbered a, b = a, c = b;
    f(a); f(b); f(c);
    return 0;
}