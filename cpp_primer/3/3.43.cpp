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
    cout << "range for" << endl;
    for (const int (&row)[4] : ia)
        for (int i : row)
            cout << i << endl;
    cout << "size_t" << endl;
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 4; j++)
            cout << ia[i][j] << endl;
    cout << "*p" << endl;
    for (int (*row)[4] = begin(ia); row != end(ia); row++)
        for (int *col = begin(*row); col != end(*row); col++)
            cout << *col << endl;
    return 0;
}