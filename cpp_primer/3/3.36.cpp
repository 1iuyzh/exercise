#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cctype>
#include <cstddef>

using std::vector;
using std::iterator;
using std::string;
using std::begin;
using std::end;
using std::cin;
using std::cout;
using std::endl;

int main(void) {
    int ia[] = {0, 1, 2};
    int ib[] = {0, 2, 1};
    for (auto i = begin(ia), j = begin(ib); (i != end(ia)) && (j != end(ib)); i++, j++)
        if (*i != *j)
            cout << "false" << endl;
    // vector
    vector<int> v1;
    vector<int> v2;
    if (v1 != v2)
        cout << "false" << endl;
    return 0;
}