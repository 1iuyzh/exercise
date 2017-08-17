#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::list;

int main() {
    vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    list<int> lst(vec.rbegin() + 3, vec.rend() - 2);
    for (auto i : lst) cout << i << ' ';
    cout << endl;
    return 0;
}