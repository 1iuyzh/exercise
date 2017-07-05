#include <iostream>

void f1(int &r1, int &r2) {
    int temp = r1;
    r1 = r2;
    r2 = temp;
}

int main() {
    int a = 1, b = 2;
    f1(a, b);
    std::cout << a << ' ' << b << std::endl;
    return 0;
}