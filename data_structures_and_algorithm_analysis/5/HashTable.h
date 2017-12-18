#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

template <typename HashedObj>
class HashTable {
public:
    explicit HashTable(int size = 101);
    
    bool contains(const HashedObj &x) const;
    void makeEmpty();
    bool remove(const HashedObj &x);
    bool insert(const HashedObj &x);

private:
    vector<list<HashedObj>> theLists;   // 链表数组
    int currentSize;

    //void rehash();
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
    theLists.resize(size);
}

template <typename HashedObj>
bool HashTable<HashedObj>::contains(const HashedObj &x) const {
    auto &whichList = theLists[myhash(x)];
    return find(whichList.begin(), whichList.end(), x) != whichList.end();
}

template <typename HashedObj>
void HashTable<HashedObj>::makeEmpty() {
    for (auto &thisList : theLists)
        thisList.clear();
}

template <typename HashedObj>
bool HashTable<HashedObj>::remove(const HashedObj &x) {
    auto &whichList = theLists[myhash(x)];
    auto itr = find(whichList.begin(), whichList.end(), x);

    if (itr == whichList.end())
        return false;
    
    whichList.erase(itr);
    --currentSize;
    return true;
}

template <typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj &x) {
    auto &whichList = theLists[myhash(x)];
    if (find(whichList.begin(), whichList.end(), x) != whichList.end())
        return false;
    whichList.push_back(x);
    currentSize++;  // del

    /*
    if (++currentSize > theLists.size())
        rehash();
    */
    
    return true;
}

template <typename HashedObj>
size_t HashTable<HashedObj>::myhash(const HashedObj &x) const {
    return myHash<HashedObj>(x) % theLists.size();
}

#endif