#include <iostream>
#include <string>
#include <cctype>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(void) {
    string s("Hello World!!!");
    for (char &c : s)
        c = 'X';
    cout << s << endl;
    return 0;
}