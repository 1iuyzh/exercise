#include <iostream>

int main() {
    const int ci = 42;
    int i = ci;
    int *const p = &i;
    return 0;
}