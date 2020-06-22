/*
 * @lc app=leetcode id=892 lang=cpp
 *
 * [892] Surface Area of 3D Shapes
 */

// @lc code=start
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
		int res = 0;
		for(int i = 0; i < grid.size(); ++i) {
			for(int j = 0; j < grid[0].size(); ++j) {
				if(grid[i][j] == 0) continue;
				res += 2; // 顶面
				int up = (i == 0) ? 0 : grid[i - 1][j];
				int down = (i == grid.size() - 1) ? 0 : grid[i + 1][j];
				int left = (j == 0) ? 0 : grid[i][j - 1];
				int right = (j == grid.size() - 1) ? 0 : grid[i][j + 1];
				if(grid[i][j] > up) res += grid[i][j] - up;
				if(grid[i][j] > down) res += grid[i][j] - down;
				if(grid[i][j] > left) res += grid[i][j] - left;
				if(grid[i][j] > right) res += grid[i][j] - right; 
			}
		}
		return res;
    }
};
// @lc code=end

