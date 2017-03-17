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
    using int_array = int[4];
    cout << "PART1" << endl;
    for (int_array &p : ia)
        for (int i : p)
            cout << i << endl;
    cout << "PART2" << endl;
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 4; j++)
            cout << ia[i][j] << endl;
    cout << "PART3" << endl;
    for (int_array *row = begin(ia); row != end(ia); row++)
        for (int *col = begin(*row); col != end(*row); col++)
            cout << *col << endl;
    return 0;
}