#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main(void) {
    int n;
    vector<int> v1;
    while (cin >> n)
        v1.push_back(n);
    auto v1_size = v1.size();
    // PART1
    for (decltype(v1.size()) i = 0; i < v1_size-1; i++)
        cout << v1[i] + v1[i+1] << endl;
    // PART2
    for (decltype(v1.size()) i = 0; i <= v1_size/2; i++)
        cout << v1[i] + v1[v1_size-1-i] << endl;
    return 0;
}