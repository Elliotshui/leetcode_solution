/*
 * @lc app=leetcode id=1037 lang=cpp
 *
 * [1037] Valid Boomerang
 */

// @lc code=start
class Solution {
public:
	bool zerovec(int x, int y) {
		return (x == 0 && y == 0);
	}
    bool isBoomerang(vector<vector<int>>& points) {
		int dx[3], dy[3];
		for(int i = 0; i < 3; ++i) {
			dx[i] = points[i][0] - points[(i + 1) % 3][0];
			dy[i] = points[i][1] - points[(i + 1) % 3][1];
			if(zerovec(dx[i], dy[i]))
				return false;
		}
		if(dx[0] * dy[1] - dx[1] * dy[0] == 0)
			return false;
		return true;
    }
};
// @lc code=end

