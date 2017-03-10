#include <iostream>
/*
 * 闭区间
 */
int main(void) {
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    while (v1 != v2) {
        std::cout << v1 << std::endl;
        v1 > v2 ? v1-- : v1++;
    }
    std::cout << v2 << std::endl;
    return 0;
}