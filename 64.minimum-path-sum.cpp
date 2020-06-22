/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int minimal[m];
        minimal[0] = grid[0][0];
        for(int j = 1; j < m; ++j) {
            minimal[j] = minimal[j - 1] + grid[0][j];
        }
        for(int i = 1; i < n; ++i) {
            minimal[0] = minimal[0] + grid[i][0];
            for(int j = 1; j < m; ++j) {
                minimal[j] = min(minimal[j - 1], minimal[j]) + grid[i][j];
            }
        }
        return minimal[m - 1];
    }
};

