#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<iostream>
#include<vector>
using namespace std;

template <typename HashedObj>
class HashTable {
public:
    explicit HashTable(int size = 101);

    bool contains(const HashedObj &x) const;
    void makeEmpty();
    bool remove(const HashedObj &x);
    bool insert(const HashedObj &x);

    enum EntryType {ACTIVE, EMPTY, DELETED};

private:
    struct HashEntry {
        HashedObj element;
        EntryType info;

        HashEntry(const HashedObj &e = HashedObj{}, EntryType i = EMPTY)
            : element{e}, info{i} {}
    };
    vector<HashEntry> arr;
    int currentSize;

    bool isActive(int currentPos) const;
    int findPos(const HashedObj &x) const;
    void rehash();
    size_t myhash(const HashedObj &x) const;
};

template <typename Key>
size_t myHash(const Key &k) {
    size_t hashVal = 0;

    for (auto &i : k)
        hashVal = 37 * hashVal + i;
    
    return hashVal;
}

template <typename HashedObj>
HashTable<HashedObj>::HashTable(int size) {
    currentSize = 0;
    arr.resize(size);
}

template <typename HashedObj>
bool HashTable<HashedObj>::contains(const HashedObj &x) const {
    return isActive(findPos(x));
}

template <typename HashedObj>
void HashTable<HashedObj>::makeEmpty() {
    currentSize = 0;
    for (auto &entry : arr)
        entry.info = EMPTY;
}

template <typename HashedObj>
bool HashTable<HashedObj>::remove(const HashedObj &x) {
    int currentPos = findPos(x);
    if (!isActive(currentPos))
        return false;
    arr[currentPos].info = DELETED;
    return true;
}

template <typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj &x) {
    int currentPos = findPos(x);
    if (isActive(currentPos))
        return false;
    
    arr[currentPos].element = x;
    arr[currentPos].info = ACTIVE;
    currentSize++;

    if (++currentSize > arr.size() / 2)
        rehash();

    return true;
}

template <typename HashedObj>
bool HashTable<HashedObj>::isActive(int currentPos) const {
    return arr[currentPos].info == ACTIVE;
}

template <typename HashedObj>
int HashTable<HashedObj>::findPos(const HashedObj &x) const {
    int offset = 1;
    int currentPos = myhash(x);

    while (arr[currentPos].info != EMPTY && arr[currentPos].element != x) {
        currentPos += offset;
        offset += 2;
        if (currentPos >= arr.size())
            currentPos -= arr.size();
    }

    return currentPos;
}

template <typename HashedObj>
void HashTable<HashedObj>::rehash() {
    vector<HashEntry> oldArray = arr;

    arr.resize(2*oldArray.size());  // 2倍大下一个素数, 没完成nextPrime
    for (auto &entry : arr)
        entry.info = EMPTY;
    
    currentSize = 0;
    for (auto &entry : oldArray)
        if (entry.info == ACTIVE)
            insert(std::move(entry.element));
}

template <typename HashedObj>
size_t HashTable<HashedObj>::myhash(const HashedObj &x) const {
    return myHash<HashedObj>(x) % arr.size();
}

#endif