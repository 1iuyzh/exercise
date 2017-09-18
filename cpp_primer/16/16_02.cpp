#include<iostream>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::string;

template <typename T>
int compare(const T &v1, const T &v2) {
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

int main() {
    cout << compare(23, 34) << endl;
    cout << compare("fff", "aaa") << endl;
    return 0;
}