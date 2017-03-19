/* 编译命令
 * g++ -c fact.cpp
 * g++ -c factMain.cpp
 * g++ fact.o factMain.o -o factMain.exe
 */
#include <iostream>
#include "Chapter6.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    for (int i = 10; i > 0; i--)
        cout << Foo() << endl;
    return 0;
}