#include <iostream>
#include <vector>
#include <iterator>

using std::vector;
using std::iterator;
using std::cin;
using std::cout;
using std::endl;

int main(void) {
    vector<int> v1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto it = v1.begin(); it != v1.end(); it++) {
        *it *= 2;
        cout << *it << endl;
    }
    return 0;
}