#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>

using std::cin; using std::cout; using std::endl;
using std::fill_n;
using std::vector;

int main() {
    vector<int> vec = { 1, 1, 2, 2 };
    fill_n(vec.begin(), 4, 0);
    for (auto i : vec)
        cout << i << ' ';
    cout << endl;
    return 0;
}