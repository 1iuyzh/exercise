#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<iostream>
using namespace std;

template <typename HashedObj>
class HashTable {
public:
    explicit HashTable(int size = 101);
    
    bool contains(const HashedObj &x) const;
    void makeEmpty();
    bool insert(const HashedObj &x);
    bool insert(HashedObj &&x);
    bool remove(const HashedObj &x);

private:
    vector<list<HashedObj>> theLists;   // 链表数组
    int currentSize;

    void rehash();
    size_t myhash(const HashedObj &x) const;
};

template <typename HashedObj>
bool HashTable<HashedObj>::contains(const HashedObj &x) const {
    auto &whichList = theLists[myhash(x)];
    return find(begin(whichList), end(whichList), x) != end(whichList);
}

template <typename HashedObj>
void HashTable<HashedObj>::makeEmpty() {
    for (auto &thisList : theLists)
        thisList.clear();
}

template <typename HashedObj>
bool HashTable<HashedObj>::remove(const HashedObj &x) {
    auto &whichList = theLists[myhash(x)];
    auto itr = find(begin(whichList), end(whichList), x);

    if (itr == end(whichList))
        return false;
    
    whichList.erase(itr);
    --currentSize;
    return true;
}

template <typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj &x) {
    auto &whichList = theLists[myhash(x)];
    if (find(begin(whichList), end(whichList), x) != end(whichList))
        return false;
    whichList.push_back(x);

    if (++currentSize > theLists.size())
        rehash();
    
    return true;
}

template <typename Key>
class hash {
public:
    size_t operator() (const Key &k) const;
};

#endif