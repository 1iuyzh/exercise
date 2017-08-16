#include<iostream>
#include<algorithm>
#include<vector>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::count;

int main() {
    vector<int> vec = { 0, 1, 1, 2, 2, 3 };
    cout << count(vec.begin(), vec.end(), 2) << endl;
    return 0;
}