#include"List.h"
#include<iostream>

using namespace std;

int main() {
    List<int> L;
    for (int i = 0; i < 10; i++)
        L.push_back(i);
    L.pop_front();
    L.pop_back();
    cout << L.size() << endl;
    cout << L.front() << ' ' << L.back() << endl;
    L.clear();
    cout << L.empty() << endl;
    return 0;
}
