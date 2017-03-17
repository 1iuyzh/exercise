#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <cstddef>

using std::vector;
using std::iterator;
using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::string;

int main(void) {
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    cout << "PART1" << endl;
    for (auto &row : ia)
        for (auto col : row)
            cout << col << endl;
    cout << "PART2" << endl;
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 4; j++)
            cout << ia[i][j] << endl;
    cout << "PART3" << endl;
    for (auto p = begin(ia); p != end(ia); p++)
        for (auto q = begin(*p); q != end(*p); q++)
            cout << *q << endl;
    return 0;
}