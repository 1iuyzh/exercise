#include "Chapter6.h"

int Foo() {
    static int i = 0;
    return i++;
}