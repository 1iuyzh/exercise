#define _UNICODE
#define UNICODE

#include"StringReverse.h"
#include<iostream>
#include<windows.h>
using std::wcout;

int main() {
    WCHAR mystr[] = L"unicode";
    PWSTR mypt = mystr;
    if (MyStringReverse(mypt))
        wcout << mypt;
    return 0;
}