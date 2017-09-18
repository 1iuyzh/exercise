#include<iostream>
#include<vector>
#include<list>
#include<string>

template <typename T, unsigned N>
constexpr unsigned getSize(const T(&)[N]) {
    return N;
}

int main() {
    std::string s[] = { "sss" };
    std::cout << getSize(s) << std::endl;

    char c[] = "s";
    std::cout << getSize(c) << std::endl;
    return 0;
}