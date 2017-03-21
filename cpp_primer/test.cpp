#include <iostream>
#include <cstdlib>  // 定义NULL

using std::cin;
using std::cout;
using std::endl;

int main() {
    const int ic = 0;
    const int *const p3;
    p3 = &ic;
    return 0;
}