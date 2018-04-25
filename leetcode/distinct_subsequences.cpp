/*
Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Example 1:
Input: S = "rabbbit", T = "rabbit"
Output: 3

Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)
rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
*/

#include<string>
#include<vector>
using std::string;
using std::vector;

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> ways(t.size() + 1);
        ways[0] = 1;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = t.size()-1; j >= 0; --j) {
                if (s[i] == t[j])
                    ways[j+1] += ways[j];
            }
        }
        return ways[t.size()];
    }
};