#ifndef SOLUTION_H
#define SOLUTION_H

#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string reverseString1(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
    
    string reverseString2(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j)
            swap(s[i++], s[j--]);
        return s;
    }
};

#endif