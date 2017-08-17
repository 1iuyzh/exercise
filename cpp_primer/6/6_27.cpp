#include <iostream>
#include <initializer_list>

using std::cin;
using std::cout;
using std::endl;
using std::initializer_list;

int foo(initializer_list<int> il) {
    int sum = 0;
    for (auto beg = il.begin(); beg != il.end(); beg++)
        sum += *beg;
    return sum;
}

int main() {
    cout << foo({1, 2, 3, 4}) << endl;
    return 0;
}