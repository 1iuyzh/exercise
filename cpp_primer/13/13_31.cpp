#include"13_30.h"

bool operator<(const HasPtr &lhs, const HasPtr &rhs) {
    // cout << "operator <" << endl;
    return *lhs.ps < *rhs.ps;
}

int main() {
    vector<HasPtr> vec;
    vec.push_back(HasPtr("a"));
    vec.push_back(HasPtr("c"));
    vec.push_back(HasPtr("b"));
    sort(vec.begin(), vec.end());
    HasPtr a("Alpha");
    HasPtr b("Beta");
    swap(a, b);
    return 0;
}