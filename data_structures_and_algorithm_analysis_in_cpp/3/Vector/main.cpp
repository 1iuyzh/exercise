#include"Vector.h"
#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<memory>
using namespace std;

int main() {
    Vector<int> Vec(10);
    for (auto it = Vec.begin(); it != Vec.end(); it++) {
        cout << *it << ' ';
        *it = 1;
    }
    cout << endl;
    for (auto it = Vec.begin(); it != Vec.end(); it++)
        cout << *it << ' ';
    cout << endl;
    return 0;
}