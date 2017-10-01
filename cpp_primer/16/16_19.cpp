#include<iostream>
#include<vector>
#include<list>
using namespace std;

// 16.19
template <typename Container>
ostream& print(const Container &con, ostream &os) {
    for (typename Container::size_type i = 0; i != con.size(); i++)
        os << con[i] << ' ';
    return os;
}

// 16.20
template <typename Container>
ostream& print2(const Container &con, ostream &os) {
    for (auto curr = con.begin(); curr != con.end(); curr++)
        os << *curr << ' ';
    return os;
}

int main() {
    vector<int> v = { 1, 23, 6, 3, 5, 3 };
    list<string> l = { "ss", "sszz", "saaas", "ssz", "sss" };
    print(v, cout) << endl;
    print2(l, cout) << endl;

    return 0;
}