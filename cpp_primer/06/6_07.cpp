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

int Foo() {
    static int i = 0;
    return i++;
}
