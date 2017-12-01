#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

// 最大连续子序列的两边一定是负数

int maxSubArray(const vector<int>& nums) {
    if (nums.empty())
        return 0;
    int sum = 0;
    int maxsum = nums[0];
    for (auto num : nums) {
        if (sum < 0)
            sum = num;
        else
            sum += num;
        if (maxsum < sum)
            maxsum = sum;
    }
    return maxsum;
}

int main() {
    vector<int> iv{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(iv) << endl;
    return 0;
}