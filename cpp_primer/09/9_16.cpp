#include <iostream>
#include <list>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::list; using std::vector;

int main() {
    list<int> l(5, 5);
    vector<int> v1(5, 4);
    vector<int> v2(5, 5);

    vector<int> v(l.begin(), l.end());

    cout << (v == v1? "true" : "false") << endl;
    cout << (v == v2? "true" : "false") << endl;

    return 0;
}