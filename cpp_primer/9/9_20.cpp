#include<iostream>
#include<list>
#include<deque>

using std::cin; using std::cout; using std::endl;
using std::list;
using std::deque;

int main() {
    list<int> ilist = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> odd, even;
    for (auto i : ilist)
        (i & 1? odd : even).push_back(i);
    for (auto i : odd) cout << i << ' ';
    cout << endl;
    for (auto i : even) cout << i << ' ';
    cout << endl;
    return 0;
}