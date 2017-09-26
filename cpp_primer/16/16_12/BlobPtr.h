#ifndef BLOBPTR_H
#define BLOBPTR_H

#include"Blob.h"
#include<memory>
#include<vector>
#include<string>

template <typename T> class BlobPtr;
template <typename T> class Blob;

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

template <typename T> class BlobPtr {
    friend bool operator==<T> (const BlobPtr<T> &, const BlobPtr<T> &);
    friend bool operator< <T> (const BlobPtr<T> &, const BlobPtr<T> &);

public:
    BlobPtr() : curr(0) { }
    BlobPtr(Blob<T> &a, size_t sz = 0) : 
        wptr(a.data), curr(sz) { }
    T&  operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    BlobPtr& operator++();
    BlobPtr& operator--();
    BlobPtr operator++(int);
    BlobPtr operator--(int);
private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const {
        if (this->wptr.lock()) {
            auto ret = this->wptr.lock();
            return ret;
        }
    }
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;   // 数组中的当前位置
};

// 前置
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
    check(curr, "increment past end of Blob");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
    --curr;
    check(curr, "decrement past begin of Blob");
    return *this;
}

// 后置
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
    BlobPtr ret = *this;
    --*this;
    return ret;
}

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    if (lhs.wptr.lock() != rhs.wptr.lock())
        throw runtime_error("ptrs to different Blobs!");
    return lhs.curr == rhs.curr;
}

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    if (lhs.wptr.lock() != rhs.wptr.lock())
        throw runtime_error("ptrs to different Blobs!");
    return lhs.curr < rhs.curr;
}

#endif