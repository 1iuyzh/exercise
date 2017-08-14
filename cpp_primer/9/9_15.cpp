#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;

int main() {
    vector<int> v1(5, 5);
    vector<int> v2(5, 4);
    vector<int> v3(5, 5);

    cout << (v1 == v2? "true" : "false") << endl;
    cout << (v1 == v3? "true" : "false") << endl;

    return 0;
}