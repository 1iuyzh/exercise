#include<iostream>
#include<string>
#include<vector>
#include"Employee.h"
#include"HashTable.h"

using namespace std;

int main() {
    HashTable<string> hashTable(101);
    vector<string> vecs{"struggle", "indignant", "sophisticated", "staggering", "gaze"};
    for (auto &s : vecs)
        hashTable.insert(s);
    cout << hashTable.contains("gaze") << endl;
    hashTable.remove("gaze");
    cout << hashTable.contains("gaze") << endl;

    return 0;
}