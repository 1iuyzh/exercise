#include<iostream>
#include<list>

using std::cin; using std::cout; using std::endl;
using std::list;

int main() {
    list<int> lst = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto  it = lst.begin();

    while (it != lst.end()) {
        if (*it & 0x1) {
            it = lst.insert(it, *it);
            it++;
            it++;
        } else
        it = lst.erase(it);
    }

    for (auto i : lst) cout << i << ' ';
    cout << endl;

    return 0;
}