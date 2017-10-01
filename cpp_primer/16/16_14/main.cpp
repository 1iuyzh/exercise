#include"Screen.h"
#include<iostream>
using namespace std;

int main() {
    Screen<5, 5> scr('*');
    Screen<5, 5> scr2;

    cout << scr;
    cin >> scr2;
    cout << scr2;

    return 0;
}