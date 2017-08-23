#include<iostream>
// 或者调用<string.h>
// strlen()返回C风格字符串数组的大小, 不包括'\0'
#include<cstring>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::string;

int main() {
    const char *s1 = "Alpha";
    const char *s2 = "Delta";
    // ()表示值初始化
    char *s = new char[strlen(s1) + strlen(s2) + 1]();
    // strcat()连接字符串
    strcat(s, s1);
    strcat(s, s2);
    cout << s << endl;
    delete [] s;

    // part 2
    string str1("Beta");
    string str2("Gamma");
    cout << str1 + str2 << endl;
    return 0;
}