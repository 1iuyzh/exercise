#ifndef CUCKOOHASHTABLE_H
#define CUCKOOHASHTABLE_H

// 未完成

#include<iostream>
#include<vector>
using namespace std;

template <typename AnyType>
class CuckooHashFamily {
public:
    size_t hash(const AnyType &x, int which) const;
    int getNumberOfFunctions();
    void generateNewFunctions();
};

template <typename AnyType, typename HashFamily>
class CuckooHashTable {
public:
    explicit CuckooHashTable(int size = 101);

private:
    struct HashEntry {
        AnyType element;
        bool isActive;

        HashEntry(const AnyType &e = AnyType(), bool a = false)
            : element{e}, isActive{a} {}
    };

    bool insertHelperl(const AnyType &xx);
    bool isActive(int currentPos) const;

    size_t myhash(const AnyType &x, int which) const;
    int findPos(const AnyType &x) const;
    void expand();
    void rehash();
    void rehash(int newSize);

    static const double MAX_LOAD = 0.40;
    static const int ALLOWED_REHASHES = 5;

    vector<HashEntry> arr;
    int CurrentSize;
    int numHashFunctions;
    int rehashes;
    HashFamily hashFunctions;
};

#endif