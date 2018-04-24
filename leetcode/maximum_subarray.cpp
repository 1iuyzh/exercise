/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

#include<vector>
#include<algorithm>
using std::vector;
using std::max;

class Solution {
public:
    int maxSubArray(const vector<int>& nums) {
        if (nums.empty())
            return 0;
        int tmp = nums[0];
        int val = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (val < 0) val = nums[i];
            else val += nums[i];
            tmp = max(tmp, val);
        }
        return val;
    }
};