#ifndef COLLECTION_H
#define COLLECTION_H

#include<iostream>
#include<vector>
using namespace std;

template <typename Object>
class Collection {
    typedef typename vector<Object>::size_type size_type;

public:
    Collection() = default;
    Collection(const initializer_list<Object>&);
    bool isEmpty();
    void makeEmpty();
    void insert(const Object&);
    void remove();
    bool contains(const Object&);

private:
    vector<Object> v;
    size_type s;
};

#endif