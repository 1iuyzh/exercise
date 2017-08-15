#include<iostream>
#include<string>
#include<deque>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::deque;

int main() {
    deque<string> std;
    string str;
    while (cin >> str)
        std.push_back(str);
    auto begin = std.begin();
    auto end = std.end();
    while (begin != end) {
        cout << *begin << ' ';
        ++begin;
    }
    cout << endl;
    return 0;
}