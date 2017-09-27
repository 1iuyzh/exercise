#include<iostream>
#include<list>
using namespace std;

template <typename T>
void printLots(list<T> L, list<int> P) {
    typename list<T>::const_iterator lIter;
    typename list<int>::const_iterator pIter;
    lIter = L.begin();
    int cnt = 1;
    for (pIter = P.begin(); pIter != P.end() && lIter != L.end(); pIter++) {
        while (cnt < *pIter && lIter != L.end()) {
            cnt++;
            lIter++;
        }
        if (lIter != L.end())
            cout << *lIter << ' ';
    }
}

int main() {
    list<int> L{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    list<int> P{ 1, 3, 4, 6 };
    printLots(L, P);
    return 0;
}