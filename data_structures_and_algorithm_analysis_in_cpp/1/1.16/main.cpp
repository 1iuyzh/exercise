#include"matrix.h"
#include<iostream>
using namespace std;

template <typename Object>
matrix<Object>::matrix(int rows, int cols) : array(rows) {
    for (auto &i : array)
        i.resize(cols);
}

template <typename Object>
const vector<Object>& matrix<Object>::operator[](int row) const {
    return array[row];
}

template <typename Object>
vector<Object>& matrix<Object>::operator[](int row) {
    return array[row];
}

template <typename Object>
int matrix<Object>::numrows() const {
    return array.size();
}

template <typename Object>
int matrix<Object>::numcols() const {
    return this->numrows() ? array[0].size() : 0;
}

int main() {
    matrix<int> m(5, 5);
    cout << m.numrows() << endl;
    cout << m.numcols() << endl;
    m[1][2] = 1;
    cout << m[1][2] << endl;
    return 0;
}