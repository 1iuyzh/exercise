#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cstddef>

using std::vector;
using std::iterator;
using std::cin;
using std::cout;
using std::endl;

int main(void) {
    int ia[10];
    for (size_t i = 0; i < 10; i++)
        ia[i] = i;
    int ib[10];
    for (size_t i = 0; i < 10; i++)
        ib[i] = ia[i];
    for (auto i : ib)
        cout << i << endl;
    // vector实现
    vector<int> va(10);
    for (auto it = va.begin(); it != va.end(); it++)
        *it = it - va.begin();
    vector<int> vb(va);
    for (auto i : vb)
        cout << i << endl;
    return 0;
}