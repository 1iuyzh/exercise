#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(void) {
    vector<int> v1;
    int n;
    while (cin >> n)
        v1.push_back(n);
    return 0;
}