/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
This is case sensitive, for example "Aa" is not considered a palindrome here.
Note:
Assume the length of given string will not exceed 1,010.
Example:
Input:
"abccccdd"
Output:
7
Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/
#include<string>
#include<map>
#include<algorithm>
using std::string;
using std::map;
using std::min;

// time:  O(N)
// space: O(1)
class Solution {
    public:
    int longestPalindrome(const string &s) {
        int val = 1;
        map<char, int> chars;
        for (auto &c : s)
            ++chars[c];
        for (auto &i : chars)
            val += i.second % 2 ? i.second - 1 : i.second;
        return min<int>(val, s.size());
    }
};