#include<iostream>
#include<sstream>
#include<string>
using namespace std;

istream &func(istream &);

int main() {
    istringstream strm("hello world\nhelloworld");
    func(strm);
    return 0;
}

istream &func(istream &is) {
    string s;
    while (is >> s)
        cout << s << endl;
    is.clear();
    return is;
}