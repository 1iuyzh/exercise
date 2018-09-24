/*
Given two strings s and t, write a function to determine if t is an anagram of s.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        vector<int> hash(256, 0);
        for (auto c : s)
            hash[c]++;
        for (auto c : t) {
            hash[c]--;
            if (hash[c] < 0)
                return false;
        }
        return true;
    }
};