/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
using std::max;

// time:  O(NlogN)
// space: O(1)
class Solution {
public:
    int maxSubArray(const vector<int>& nums) {
        if (nums.empty()) return 0;
        int left = 0, right = nums.size() - 1;
        return maxSubArray(nums, left, right);
    }
    int maxSubArray(const vector<int>& nums, int left, int right) {
        if (left == right)
            return nums[left];
        int mid = (left + right) / 2;
        int maxLeftSum = maxSubArray(nums, left, mid);
        int maxRightSum = maxSubArray(nums, mid + 1, right);

        int maxLeftBorderSum = nums[mid], leftBorderSum = 0;
        for (int i = mid; i >= left; --i) {
            leftBorderSum += nums[i];
            maxLeftBorderSum = max(maxLeftBorderSum, leftBorderSum);
        }

        int maxRightBorderSum = nums[mid+1], rightBorderSum = 0;
        for (int i = mid+1; i <= right; ++i) {
            rightBorderSum += nums[i];
            maxRightBorderSum = max(maxRightBorderSum, rightBorderSum);
        }

        int maxBorderSum = maxLeftBorderSum + maxRightBorderSum;

        return max(max(maxLeftSum, maxRightSum), maxBorderSum);
    }
};

int main() {
    vector<int> nums{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int ret = Solution().maxSubArray(nums);
    std::cout << ret << std::endl;
    return 0;
}