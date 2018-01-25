//#define _UNICODE
//#define UNICODE

#include"StringReverse.h"
#include<iostream>
#include<windows.h>
using std::wcout;
using std::endl;

int main() {
    TCHAR str[] = _T("abcdef");
    PTSTR pt = str;
    if (MyStringReverse(pt))
        wcout << pt << endl;
    return 0;
}