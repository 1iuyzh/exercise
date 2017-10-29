#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::list;
using std::string;
using std::vector;

int main() {
    list<const char *> l1 = {"Milton", "Shakespeare", "Austen"};
    vector<string> v1;
    v1.assign(l1.begin(), l1.end());
    for (auto i : v1) cout << i << ' ';
    cout << endl;
    return 0;
}