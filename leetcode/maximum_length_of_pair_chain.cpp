/*
You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.
Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.
Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]

Note:
The number of given pairs will be in the range [1, 1000].
*/

#include<vector>
using std::vector;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int len = 0;
        if (!pairs.empty())
            len = 1;
        quickSort(pairs, 0, pairs.size()-1);
        vector<int> tmp = pairs[0];
        for (int i = 1; i < pairs.size(); i++) {
            if (tmp[1] < pairs[i][0]) {
                len++;
                tmp = pairs[i];
            }
        }
        return len;
    }
private:
    void insertSort(vector<vector<int>> &a, int left, int right) {
        for (int i = left+1; i <= right; i++) {
            vector<int> tmp = std::move(a[i]);
            int j = 0;
            for (j = i-1; j >= 0 && (tmp[1] < a[j][1] || (tmp[1] == a[j][1] && tmp[0] < a[j][0])); --j)
                a[j+1] = std::move(a[j]);
            a[j+1] = std::move(tmp);
        }
    }
    void quickSort(vector<vector<int>> &a, int left, int right) {
        if (right - left >= 10) {
            int center = (left + right) / 2;
            if (a[center][1] < a[left][1] || (a[center][1] == a[left][1] && a[center][0] < a[left][0]))
                swap(a[left], a[center]);
            if (a[right][1] < a[left][1] || (a[right][1] == a[left][1] && a[right][0] < a[left][0]))
                swap(a[left], a[right]);
            if (a[right][1] < a[center][1] || (a[right][1] == a[center][1] && a[right][0] < a[center][0]))
                swap(a[center], a[right]);
            swap(a[center], a[right-1]);
            int i = left, j = right - 1;
            while (i < j) {
                while (a[++i][1] < a[right-1][1] || (a[i][1] == a[right-1][1] && a[i][0] < a[right-1][0]));
                while (a[--j][1] > a[right-1][1] || (a[j][1] == a[right-1][1] && a[j][0] > a[right-1][0]));
                if (i < j)
                    swap(a[i], a[j]);
            }
            swap(a[i], a[right-1]);
            quickSort(a, left, i-1);
            quickSort(a, i+1, right);
        }
        else
            insertSort(a, left, right);
    }
};