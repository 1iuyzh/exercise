#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool f1(const string &);
void f2(string &);

int main() {
    cout << f1("helloworld") << endl;
    string s = "HELLOWORLD";
    f2(s);
    cout << s << endl;
    return 0;
}

bool f1(const string &s) {
    for (auto c : s)
        if (isupper(c))
            return true;
    return false;
}

void f2(string &s) {
    for (auto &c : s)
        c = tolower(c);
    cout << s << endl;
}