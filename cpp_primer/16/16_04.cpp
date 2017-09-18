#include<iostream>
#include<string>
#include<vector>
#include<list>

using std::cin; using std::cout; using std::endl;
using std::string;

template <typename Iterator, typename Value>
auto find(Iterator first, Iterator last, const Value &value) {
    for (; first != last && *first != value; ++first);
    return first;
}

int main() {
    std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto it = find(v.cbegin(), v.cend(), 5);
    cout << (it != v.cend()) << endl;
    std::list<string> l = { "aa", "bb", "cc", "dd", "ee", "ff", "gg" };
    auto lit = find(l.cbegin(), l.cend(), "zz");
    cout << (lit != l.cend()) << endl;
    return 0;
}