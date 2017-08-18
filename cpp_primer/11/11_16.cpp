#include<iostream>
#include<string>
#include<map>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::map;

int main() {
    map<int, string> m;
    m[25] = "Alan";
    auto it = m.begin();
    it->second = "Wang";
    cout << it->first << ' ' << it->second << endl;
    return 0;
}