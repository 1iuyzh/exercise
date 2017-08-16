#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void foo(const vector<int> &v1, decltype(v1.size()) i1, decltype(v1.size()) i2) {
    if (i1 == i2) {
        cout << v1[i1] << endl;
        return;
    }
    cout << v1[i1] << endl;
    foo(v1, i1+1, i2);
}

int main() {
    vector<int> v1(10, -1);
    foo(v1, 0, 9);
    return 0;
}