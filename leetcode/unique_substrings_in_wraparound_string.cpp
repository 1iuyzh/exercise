/*
Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
Now we have another string p. Your job is to find out how many unique non-empty substrings of p are present in s. In particular, your input is the string p and you need to output the number of different non-empty substrings of p in the string s.

Note: p consists of only lowercase English letters and the size of p might be over 10000.

Example 1:
Input: "a"
Output: 1
Explanation: Only the substring "a" of string "a" is in the string s.

Example 2:
Input: "cac"
Output: 2
Explanation: There are two substrings "a", "c" of string "cac" in the string s.

Example 3:
Input: "zab"
Output: 6
Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.
*/

#include<string>
#include<map>
#include<algorithm>
using std::string;
using std::map;
using std::max;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int num = 0;
        map<char, int> m;
        if (p.empty())
            return 0;
        for (int i = 0, j = 0; i < p.size();) {
            while (j+1 < p.size() && (p[j+1] - p[j] == 1 || (p[j] == 'z' && p[j+1] == 'a')))
                j++;
            while (i <= j) {
                if (m.find(p[i]) == m.end())
                    m[p[i]] = j - i + 1;
                else
                    m[p[i]] = max(m[p[i]], j-i+1);
                i++;
            }
            j = i;
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            num += it->second;
        }
        return num;
    }
};