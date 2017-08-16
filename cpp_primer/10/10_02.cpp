#include<iostream>
#include<algorithm>
#include<list>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::count;
using std::list;
using std::string;

int main() {
    string str;
    list<string> lst;
    while (cin >> str) {
        lst.push_back(str);
    }
    cout << count(lst.begin(), lst.end(), "is") << endl;
    return 0;
}