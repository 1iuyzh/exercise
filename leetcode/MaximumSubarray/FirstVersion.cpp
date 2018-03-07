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

// time:  O(N)
// space: O(1)
class Solution {
public:
    int maxSubArray(const vector<int>& nums) {
        if (nums.empty()) return 0;
        int val = nums[0];
        int tmp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (tmp < 0) tmp = nums[i];
            else tmp += nums[i];
            val = max(val, tmp);
        }
        return val;
    }
};