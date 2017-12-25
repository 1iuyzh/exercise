#include"Vector.h"
#include<iostream>

using namespace std;

int main() {
    Vector<int> Vec(0);
    for (int i = 0; i < 10; i++)
        Vec.push_back(i);
    for (auto i : Vec)
        cout << i << endl;
    cout << Vec.size() << ' ' << Vec.capacity() << endl;
    Vector<int> Vec_new(Vec);
    cout << Vec_new.back() << endl;
    Vec.resize(5);
    for (auto i = Vec.begin(); i != Vec.end(); i++)
        cout << *i << endl;
    cout << Vec.size() << ' ' << Vec.capacity() << endl;
    Vec_new = Vec;
    cout << Vec_new.back() << endl;
    Vec.pop_back();
    cout << Vec.back() << endl;
    return 0;
}