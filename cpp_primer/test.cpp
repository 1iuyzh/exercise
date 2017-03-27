#include <iostream>
#include <string> // 标准库类型string
#include <cstdlib> // 定义NULL
#include <cctype> // 处理字符的函数, 比如isalpha(c), toupper(c)等
#include <vector>
#include <cstddef> // 定义size_t: 数组下标类型, 定义ptrdiff_t: 指针相减的类型

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
// string::size_type: s.size()的返回类型, string对象的下标类型
// vector<int>::size_type: v.size()的返回类型, vector<int>的下标类型
// string::iterator, string::const_iterator: string的迭代器类型
// vector<int>::iterator, vector<int>::const_iterator: vector<int>的迭代器类型
int main() {
    int a = 1;
    int *p = &a;
    decltype((a)) b = a;
    decltype(*p) c = b;
    cout << b << endl;
    cout << c << endl;
    return 0;
}