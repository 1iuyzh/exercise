#include<iostream>
#include<vector>

using std::cin; using std::cout; using std::endl;
using std::vector;

int main() {
    vector<int> vec = { 0, 1, 2, 3, 4 };
    for (auto r_begin = vec.crbegin(), r_end = vec.crend(); r_begin != r_end; r_begin++)
        cout << *r_begin << ' ';
    cout << endl;
    return 0;
}