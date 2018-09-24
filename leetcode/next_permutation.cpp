/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length = nums.size();
        if (length <= 1)
            return;
        int temp = nums[length - 1];
        for (int i = length - 2; i >= 0; --i) {
            if (temp > nums[i]) {
                quicksort(nums, i+1, length-1);
                int j = i+1;
                while (nums[j] <= nums[i])
                    j++;
                std::swap(nums[i], nums[j]);
                return;
            }
            else
                temp = nums[i];
        }
        std::reverse(nums.begin(), nums.end());
        return;
    }
private:
    void quicksort(vector<int>& nums, int left, int right) {
        if (left == right)
            return;
        if (right - left == 1) {
            if (nums[right] < nums[left])
                std::swap(nums[left], nums[right]);
            return;
        }
        int mid = (left + right) / 2;
        if (nums[mid] < nums[left])
            std::swap(nums[left], nums[mid]);
        if (nums[right] < nums[left])
            std::swap(nums[left], nums[right]);
        if (nums[right] < nums[mid])
            std::swap(nums[mid], nums[right]);
        std::swap(nums[mid], nums[right - 1]);
        int i = left;
        int j = right - 1;
        while (i < j) {
            while (nums[++i] < nums[right-1]);
            while (nums[--j] > nums[right-1]);
            if (i < j)
                std::swap(nums[i], nums[j]);
        }
        std::swap(nums[i], nums[right-1]);
        quicksort(nums, left, i-1);
        quicksort(nums, i+1, right);
    }
};