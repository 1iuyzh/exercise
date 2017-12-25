#ifndef VECTOR_H
#define VECTOR_H

#include<iostream>
#include<algorithm>
using namespace std;

template <typename Object>
class Vector {
    
public:
    explicit Vector(int initSize = 0);
    Vector(const Vector &rhs);
    Vector(Vector &&rhs);
    Vector& operator=(const Vector &rhs);
    Vector& operator=(Vector &&rhs);
    ~Vector();

    Object& operator[](int index);
    const Object& operator[](int index) const;
    void resize(int newSize);
    void reserve(int newCapacity);
    bool empty() const;
    int size() const;
    int capacity() const;

    void push_back(const Object& x);
    void push_back(Object &&x);
    void pop_back();
    const Object& back() const;

    typedef Object * iterator;
    typedef const Object * const_iterator;
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    static const int SPARE_CAPACITY = 16;

private:
    int theSize;
    int theCapacity;
    Object *objects;
};

template <typename Object>
Vector<Object>::Vector(int initSize) : theSize(initSize), theCapacity(initSize+SPARE_CAPACITY) {
    objects = new Object[theCapacity];
}

template <typename Object>
Vector<Object>::Vector(const Vector &rhs): theSize(rhs.theSize), theCapacity(rhs.theCapacity), objects(nullptr) {
    objects = new Object[theCapacity];
    for (int k = 0; k < theSize; ++k)
        objects[k] = rhs.objects[k];
}

template <typename Object>
Vector<Object>::Vector(Vector &&rhs) : theSize(rhs.theSize), theCapacity(rhs.theCapacity), objects(rhs.objects) {
    rhs.objects = nullptr;
    rhs.theSize = 0;
    rhs.theCapacity = 0;
}

template <typename Object>
Vector<Object>& Vector<Object>::operator=(const Vector &rhs) {
    Vector copy = rhs;
    std::swap(*this, copy);
    return *this;
}

template <typename Object>
Vector<Object>& Vector<Object>::operator=(Vector &&rhs) {
    std::swap(theSize, rhs.theSize);
    std::swap(theCapacity, rhs.theCapacity);
    std::swap(objects, rhs.objects);
    // std::swap(*this, rhs);
    // std::move()
    return *this;
}

template <typename Object>
Vector<Object>::~Vector() {
    delete [] objects;
}

template <typename Object>
Object& Vector<Object>::operator[](int index) {
    return objects[index];
}

template <typename Object>
const Object& Vector<Object>::operator[](int index) const {
    return objects[index];
}

template <typename Object>
void Vector<Object>::resize(int newSize) {
    if (newSize > theCapacity)
        reserve(newSize * 2);
    theSize = newSize;
    //?
}

template <typename Object>
void Vector<Object>::reserve(int newCapacity) {
    if (newCapacity < theSize)
        return;
    Object *newArray = new Object[newCapacity];
    for (int k = 0; k < theSize; k++)
        newArray[k] = std::move(objects[k]);
    
    theCapacity = newCapacity;
    std::swap(objects, newArray);
    delete [] newArray;
}

template <typename Object>
bool Vector<Object>::empty() const {
    return size() == 0;
}

template <typename Object>
int Vector<Object>::size() const {
    return theSize;
}

template <typename Object>
int Vector<Object>::capacity() const {
    return theCapacity;
}

template <typename Object>
void Vector<Object>::push_back(const Object &x) {
    if (theSize == theCapacity)
        reserve(2 * theCapacity + 1);
    objects[theSize++] = x;
}

template <typename Object>
void Vector<Object>::push_back(Object &&x) {
    if (theSize == theCapacity)
        reserve(2 * theCapacity + 1);
    objects[theSize++] = std::move(x);
}

template <typename Object>
void Vector<Object>::pop_back() {
    --theSize;
}

template <typename Object>
const Object& Vector<Object>::back() const {
    return objects[theSize-1];
}

template <typename Object>
typename Vector<Object>::iterator Vector<Object>::begin() {
    return &objects[0];
}

template <typename Object>
typename Vector<Object>::const_iterator Vector<Object>::begin() const {
    return &objects[0];
}

template <typename Object>
typename Vector<Object>::iterator Vector<Object>::end() {
    return &objects[size()];
}

template <typename Object>
typename Vector<Object>::const_iterator Vector<Object>::end() const {
    return &objects[size()];
}

#endif
