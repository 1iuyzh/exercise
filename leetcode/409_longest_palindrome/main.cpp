#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int longestPalindrome(const string &s) {
    int res = 1, list[256] = {0};
    for (auto &c : s)
        list[c]++;
    for (auto &i : list)
        res += i%2 ? i-1 : i;
        //res += i & ~1;
    return min<int>(res, s.size());
}

int main() {
    string s = "abccccdd";
    cout << longestPalindrome(s) << endl;
    return 0;
}