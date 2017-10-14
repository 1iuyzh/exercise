#include<iostream>
#include<string>
using namespace std;

istream &func1(istream &);
istream &func2(istream &);

int main() {
    istream &is = func2(cin);
    cout << is.rdstate() << endl;
    return 0;
}

istream &func1(istream &is) {
    char c;
    // 标准输入, is.eof()何时置1? 单独一行输入eof时, is.eof()返回true
    while (is >> c)
        cout << c;
    cout << endl;
    is.clear();
    return is;
}

istream &func2(istream &is) {
    string s;
    // 标准输入, is.eof()何时置1? 单独一行输入eof时, is.eof()返回true
    // 模型: 控制台 --> buffer --> 程序?
    while (is >> s)
        cout << s << endl;
    is.clear();
    return is;
}