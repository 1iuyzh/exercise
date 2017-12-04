#ifndef BLOB_H
#define BLOB_H

#include"BlobPtr.h"
#include<memory>
#include<vector>
#include<string>

template <typename> class BlobPtr;

template <typename T> class Blob {
    friend class BlobPtr<T>;
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    Blob();
    Blob(std::initializer_list<T> il);
    // new
    template<typename It>
    Blob(It b, It e);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T& t) { data->push_back(t); }
    void push_back(T&& t) { data->push_back(std::move(t)); }
    void pop_back();
    T& back();
    T& front();
    T& operator[](size_type i);
    const T& back() const;
    const T& front() const;
    const T& operator[](size_type i) const;
private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const;
};

template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) { }

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : 
    data(std::make_shared<std::vector<T>>(il)) { }

// new
template <typename T>
template <typename It>
Blob<T>::Blob(It b, It e) : data(make_shared<vector<T>>(b, e)) { }

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T>
T& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
const T& Blob<T>::back() const {
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T& Blob<T>::front() {
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T>
const T& Blob<T>::front() const {
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T>
T& Blob<T>::operator[](size_type i) {
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
const T& Blob<T>::operator[](size_type i) const {
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back() {
    check(0, "pop_bacl on empty Blob");
    data->pop_back();
}

#endif