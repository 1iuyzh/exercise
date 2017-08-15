#include<iostream>
#include<vector>
#include<list>
#include<iterator>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::list;
using std::end;

int main() {
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    vector<int> vec(ia, end(ia));
    list<int> lst(vec.begin(), vec.end());

    for (auto it = vec.begin(); it != vec.end(); ) {
        if (! (*it & 0x1)) it = vec.erase(it);
        else ++it;
    }

    for (auto it = lst.begin(); it != lst.end(); ) {
        if (*it & 0x1) it = lst.erase(it);
        else ++it;
    }

    for (auto i : vec) cout << i << ' ';
    cout << endl;
    for (auto i : lst) cout << i << ' ';

    return 0;
}