#include<iostream>
#include<forward_list>

using std::cin; using std::cout; using std::endl;
using std::forward_list;

int main() {
    forward_list<int> lst(5, 5);

    for (auto i : lst) cout << i << ' ';
    cout << endl;

    auto it = lst.insert_after(lst.before_begin(), {1, 2, 3, 4});

    for (auto i : lst) cout << i << ' ';
    cout << endl;

    cout << *it;

    return 0;
}