#include <iostream>
#include <string> // 标准库类型string
#include <vector>
#include <iterator> // 标准库函数begin(), end()
#include <initializer_list> // 表示可变形参的标准库类型initialzier_list
#include <cstdlib> // 定义NULL
#include <cctype> // 处理字符的函数, 比如isalpha(c), toupper(c)等
#include <cstddef> // 定义size_t: 数组下标类型, 定义ptrdiff_t: 指针相减的类型

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::initializer_list;
// string::size_type: s.size()的返回类型, string对象的下标类型
// vector<int>::size_type: v.size()的返回类型, vector<int>的下标类型
// string::iterator, string::const_iterator: string的迭代器类型
// vector<T>::iterator, vector<T>::const_iterator: vector<T>的迭代器类型
// initializer_list<T>
int main() {
    int a = 1;
    int *p = &a;
    decltype((a)) b = a;
    decltype(*p) c = b;
    cout << b << endl;
    cout << c << endl;
    return 0;
}