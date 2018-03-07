/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
You may assume no duplicate exists in the array.
*/
#include<vector>
using std::vector;

class Solution {
    public:
    int findMin(vector<int> &nums) {
        int val = 0;
        val = nums[0];
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] < val)
                return nums[i];
        return val;
    }
};