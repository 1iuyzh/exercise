#include"LeftistHeap.h"
#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> v1 = {3, 10, 8, 21, 14, 17, 23, 26};
    vector<int> v2 = {6, 12, 7, 18, 24, 37, 18, 33};
    LeftistHeap<int> h1;
    LeftistHeap<int> h2;
    for (auto &i : v1)
        h1.insert(i);
    for (auto &i : v2)
        h2.insert(i);
    h1.printHeap();
    cout << endl;
    h2.printHeap();
    cout << endl;
    h1.merge(h2);
    h1.printHeap();
    cout << endl;
    h1.deleteMin();
    h1.printHeap();

    return 0;
}