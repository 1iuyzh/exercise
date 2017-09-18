#include<iostream>
#include<string>

using std::cin; using std::cout; using std::endl;

template <typename T, unsigned N>
void print(const T (&arr)[N]) {
    for (auto i : arr)
        cout << i << ' ';
}

int main() {
    std::string sarr[5] = { "aa", "bb", "cc", "dd", "ee" };
    int iarr[5] = { 0, 1, 2, 3, 4 };
    print(sarr);
    cout << endl;
    print(iarr);
    cout << endl;
    return 0;
}