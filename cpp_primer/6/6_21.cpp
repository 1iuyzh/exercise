#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int f1(const int &, const int *);

int main() {
    int i1, i2;
    cin >> i1 >> i2;
    cout << f1(i1, &i2) << endl;
    return 0;
}

int f1(const int &i, const int *pi) {
    return (i > *pi)? i : *pi;
}