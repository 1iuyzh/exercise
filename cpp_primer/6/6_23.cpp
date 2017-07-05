#include <iostream>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;

// 函数重载
void print(int i) {
    cout << i << endl;
}

void print(const int j[1], size_t size) {
    decltype(size) i = 0;
    while (i < size) {
        cout << j[i] << endl;
        i++;
    }
}

void print(const int *begin, const int *end) {
    if (begin == end)
        cout << *begin << endl;
    while (begin != end) {
        cout << *begin << endl;
        begin++;
    }
}

void print(const int (&j)[2]) {
    for (auto c : j)
        cout << c << endl;
}

int main() {
    int i = 0;
    int j[2] = {0, 1};
    print(i);
    print(j, 2);
    print(begin(j), end(j));
    print(j);
}