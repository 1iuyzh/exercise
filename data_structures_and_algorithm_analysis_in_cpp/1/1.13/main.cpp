#include"Collection.h"
#include<iostream>
using namespace std;

template <typename Object>
Collection<Object>::Collection(const initializer_list<Object> &il) : v(il), s(v.size()) { }

template <typename Object>
bool Collection<Object>::isEmpty() {
    return s == 0;
}

template <typename Object>
void Collection<Object>::makeEmpty() {
    v = vector<Object>();
    s = 0;
}

template <typename Object>
void Collection<Object>::insert(const Object &x) {
    v.push_back(x);
    s++;
}

template <typename Object>
void Collection<Object>::remove() {
    if (!this->isEmpty()) {
        v.pop_back();
        s--;
    }
}

template <typename Object>
bool Collection<Object>::contains(const Object &x) {
    for (auto i : v)
        if (i == x)
            return true;
    return false;
}

int main() {
    Collection<int> c = { 1, 2, 3, 4 };
    cout << "if 2 in c? " << c.contains(2) << endl;
    cout << "if c is empty? " << c.isEmpty() << endl;
    c.makeEmpty();
    cout << "if c is empty? " << c.isEmpty() << endl;
    c.insert(0);
    cout << "if 0 in c? " << c.contains(0) << endl;
    cout << "if c is empty? " << c.isEmpty() << endl;
    c.remove();
    cout << "if 0 in c? " << c.contains(0) << endl;
    cout << "if c is empty? " << c.isEmpty() << endl;
    return 0;
}