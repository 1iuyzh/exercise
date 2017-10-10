#ifndef VECTOR_H
#define VECTOR_H

#include<iostream>
#include<vector>
#include<memory>
using namespace std;

template <typename T>
class Vector {
public:
    explicit Vector(int initSize = 0) : theSize(initSize), theCapacity(initSize + SPARE_CAPACITY) {
        pt = new T[theCapacity];
    }
    Vector(const Vector &rhs) : pt(NULL) {
        operator=(rhs);
    }
    ~Vector() {
        delete [] pt;
    }
    const Vector& operator=(const Vector &rhs) {
        if (this != &rhs) {
            delete [] pt;
            theSize = rhs.size();
            theCapacity = rhs.theCapacity;
            pt = new T[capacity()];
            for (int i = 0; i < size(); i++)
                pt[i] = rhs.pt[i];
        }
        return *this;
    }
    void resize(int newSize) {
        if (newSize > theCapacity)
            reserve(newSize * 2 + 1);
        theSize = newSize;
    }
    void reserve(int newCapacity) {
        if (newCapacity < theSize)
            return;
        T *oldpt = pt;
        pt = new T[newCapacity];
        for (int i = 0; i < theSize; i++)
            pt[i] = oldpt[i];
        theCapacity = newCapacity;
        delete [] oldpt;
    }
    T& operator[](size_t index) {
        return pt[index];
    }
    const T& operator[](size_t index) const {
        return pt[index];
    }
    bool empty() const {
        return size() == 0;
    }
    int size() const {
        return theSize;
    }
    int capacity() const {
        return theCapacity;
    }
    void push_back(const T &x) {
        if (theSize == theCapacity)
            reserve(2 * theCapacity + 1);
        pt[theSize++] = x;
    }
    void pop_back() {
        theSize--;
    }
    const T& back() const {
        return pt[theSize - 1];
    }
    T* begin() {
        return &pt[0];
    }
    const T* begin() const {
        return &pt[0];
    }
    T* end() {
        return &pt[theSize];
    }
    const T* end() const {
        return &pt[theSize];
    }
    enum { SPARE_CAPACITY = 16 };
private:
    int theSize;
    int theCapacity;
    T *pt;
};

#endif