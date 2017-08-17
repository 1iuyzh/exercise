#include <iostream>

void f1(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int a = 1, b = 2;
    f1(&a, &b);
    std::cout << a << ' ' << b << std::endl;
    return 0;
}