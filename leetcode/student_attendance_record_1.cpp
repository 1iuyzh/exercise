/*
You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).
You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False
*/

#include <string>
using std::string;

class Solution {
public:
    bool checkRecord(string s) {
        int num_a = 0;
        int num_l_max = 0;
        int num_l = 0;
        char c_last = 'P';
        for (const auto &c : s) {
            if (c == 'A')
                ++num_a;
            if (c == 'L') {
                if (c_last == 'L')
                    ++num_l;
                else
                    num_l = 1;
                if (num_l_max < num_l)
                    num_l_max = num_l;
            }
            c_last = c;
        }
        if (num_a > 1 || num_l_max > 2)
            return false;
        else
            return true;
    }
};