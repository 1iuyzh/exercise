/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:
It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

#include<vector>
using std::vector;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num + 1);
        for (int i = 0; i <= num; ++i)
            v[i] = i % 2 == 0 ? v[i/2] : v[i/2] + 1;
        return v;
    }
};

class Solution2 {
public:
    vector<int> countBits(int num) {
        vector<int> v(num + 1);
        for (int i = 1; i <= num; ++i)
            v[i] = (i & 1) + v[i >> 1];
        return v;
    }
}