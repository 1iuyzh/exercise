#include<iostream>
#include<vector>
#include<iterator>

using std::cin; using std::cout; using std::endl;
using std::vector;

int main() {
    vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto it_1 = back_inserter(vec);
    // auto it_2 = front_inserter(vec);
    auto it_3 = inserter(vec, vec.begin());
    *it_3 = 0;
    for (auto i : vec) cout << i << ' ';
    cout << endl;
    // *it_2 = 2;
    // for (auto i : vec) cout << i << ' ';
    // cout << endl;
    *it_1 = 0;
    for (auto i : vec) cout << i << ' ';
    cout << endl;
    return 0;
}