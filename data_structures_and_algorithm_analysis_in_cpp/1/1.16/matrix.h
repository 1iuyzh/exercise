#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
#include<vector>
using namespace std;

template <typename Object>
class matrix {
    typedef Object value_type;
    
public:
    matrix() = default;
    matrix(int rows, int cols);
    const vector<value_type>& operator[](int) const;
    vector<value_type>& operator[](int);
    int numrows() const;
    int numcols() const;
    void resize(int);

private:
    vector<vector<value_type>> array;
};

#endif