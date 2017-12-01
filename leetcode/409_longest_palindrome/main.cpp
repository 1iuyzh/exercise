#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int longestPalindrome(const string &s) {
    map<char, int> m;
    for (auto &c : s)
        m[c]++;
    int res = 0;
    for (auto i : m)
        res += i.second%2 ? (res%2? i.second-1 : i.second) : i.second;
    return res;
}

int main() {
    string s = "abccccdd";
    cout << longestPalindrome(s) << endl;
    return 0;
}