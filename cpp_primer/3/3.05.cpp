#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(void) {
    string s1, s2;
    if (cin >> s1)
        s2 = s1;
    while (cin >> s1)
        s2 += (' ' + s1);
    cout << s2 << endl;
    return 0;
}