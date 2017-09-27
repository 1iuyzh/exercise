#include<iostream>
#include<vector>
using namespace std;

template <typename Iterator, typename Object>
Iterator my_find(Iterator start, Iterator end, const Object &x) {
    for (Iterator it = start; it != end; it++)
        if (*it == x)
            return it;
    return end;
}

int main() {
    vector<int> v{ 1, 2, 3, 4, 5 };
    cout << *my_find(v.begin(), v.end(), 3) << endl;
    return 0;
}