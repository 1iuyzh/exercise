/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.

Example 2:
[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.

Note: The length of each dimension in the given grid does not exceed 50.
*/

#include <vector>
using std::vector;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> k(grid.size(), vector<int>(grid[0].size(), 0)); //可以省去标记, 考虑负数作标记
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (k[i][j] == 0 && grid[i][j] == 1 && (i == 0 || grid[i-1][j] == 0) && (j == 0 || grid[i][j-1] == 0)) {
                    int area = getArea(grid, k, i, j);
                    if (max_area < area)
                        max_area = area;
                }
            }
        }
        return max_area;
    }
private:
    int getArea(vector<vector<int>>& grid, vector<vector<int>>& k, int i, int j) {
        k[i][j] = 1;
        int area = 1;
        if (i != 0 && grid[i-1][j] == 1 && k[i-1][j] == 0)
            area += getArea(grid, k, i-1, j);
        if (i != grid.size()-1 && grid[i+1][j] == 1 && k[i+1][j] == 0)
            area += getArea(grid, k, i+1, j);
        if (j != 0 && grid[i][j-1] == 1 && k[i][j-1] == 0)
            area += getArea(grid, k, i, j-1);
        if (j != grid[0].size()-1 && grid[i][j+1] == 1 && k[i][j+1] == 0)
            area += getArea(grid, k, i, j+1);
        return area;
    }
};