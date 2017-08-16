#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::accumulate;

int main() {
    vector<int> vec = { 1, 2, 3, 4 };
    cout << accumulate(vec.begin(), vec.end(), 0) << endl;
    return 0;
}