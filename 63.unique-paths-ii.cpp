/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if(n == 0)
            return 0;
        int m = obstacleGrid[0].size();
        if(m == 0)
            return 0;

        int paths[m];
        paths[0] = 1 - obstacleGrid[0][0];
        for(int j = 1; j < m; ++j) {
            if(obstacleGrid[0][j] == 1)
                paths[j] = 0;
            else 
                paths[j] = paths[j - 1];
        }
        for(int i = 1; i < n; ++i) {
            long long tmp = 0;
            for(int j = 0; j < m; ++j) {
                if(obstacleGrid[i][j] == 1) {
                    paths[j] = 0;
                    tmp = 0;
                }
                else {
                    paths[j] = tmp + paths[j];
                    tmp = paths[j];
                }
            }
        }
        return paths[m - 1];
    }
};

