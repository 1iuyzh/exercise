#include<iostream>
#include<string>

template <typename T, unsigned N>
auto my_begin(const T (&arr)[N]) {
    return arr;
}

template <typename T, unsigned N>
auto my_end(const T (&arr)[N]) {
    return arr + N;
}

int main() {
    std::string s[] = { "sssss", "ss", "ss", "sss" };
    std::cout << *my_begin(s) << std::endl;
    std::cout << *(my_end(s) - 1) << std::endl;
    return 0;
}