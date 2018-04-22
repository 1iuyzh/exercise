/*
Given a string S and a string T, count the number of distinct subsequences of S which equals T.
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
*/
#include<string>
#include<vector>
using std::string;
using std::vector;

class Solution {
public:
    typedef string::iterator iter;
    int numDistinct(string s, string t) {
        return func(s.begin(), s.end(), t.begin(), t.end());
    }
    int func(iter left, iter right, iter begin, iter end) {
        if (begin == end)
            return 1;
        if (left == right)
            return 0;
        if (*left == *begin)
            return func(left + 1, right, begin, end) + func(left + 1, right, begin + 1, end);
        else
            return func(left + 1, right, begin, end);
    }
};