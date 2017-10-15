#include<iostream>
#include<string>
using namespace std;

istream &func1(istream &);
istream &func2(istream &);

int main() {
    istream &is1 = func1(cin);
    cout << is1.rdstate() << endl;
    istream &is2 = func2(cin);
    cout << is2.rdstate() << endl;
    return 0;
}

istream &func1(istream &is) {
    char c;
    // 标准输入, is.eof()何时置1?
    // 空格、回车被程序忽略
    // ^Z在行首才会被识别
    while (is >> c)
        cout << c;
    cout << endl;
    is.clear();
    return is;
}

istream &func2(istream &is) {
    string s;
    // 标准输入, is.eof()何时置1?
    // 模型: 控制台 --> buffer --> 程序
    // 数据从控制台到缓冲区后, 程序自动从缓冲区内读取数据
    // 控制台输入的回车也被读取到缓冲区内, 被程序忽略
    // 保存的数据是string, 两个string之间需要空格、回车等分隔
    while (is >> s)
        cout << s << endl;
    is.clear();
    return is;
}