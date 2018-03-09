/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/
#include<string>
#include<algorithm>
using std::string;
using std::swap;

// time:  O(N)
// space: O(1)
class Solution {
public:
    string reverseString(string s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
            swap(s[i], s[j]); 
        return s;
    }
};