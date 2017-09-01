#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>

int main() {
    std::vector<int> ivec { 2, 3, 4 };
    int input;
    std::cin >> input;
    std::modulus<int> mod;
    auto is_divisible = std::any_of(ivec.cbegin(), ivec.cend(), [&](int i){ return mod(input, i) == 0; });
    std::cout << (is_divisible ? "yes" : "no") << std::endl;
    return 0;
}