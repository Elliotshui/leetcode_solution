/*
 * @lc app=leetcode id=799 lang=cpp
 *
 * [799] Champagne Tower
 */

// @lc code=start
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
		vector<vector<double>> vol(101, vector<double>(101, 0.0));
		vol[0][0] = poured;
		for(int i = 0; i < 100; ++i) {
			for(int j = 0; j <= i; ++j) {
				if(vol[i][j] > 1.0) {
					vol[i + 1][j] += (vol[i][j] - 1.0) / 2;
					vol[i + 1][j + 1] += (vol[i][j] - 1.0) / 2;
					vol[i][j] = 1.0;
				}
			}
		}
		return vol[query_row][query_glass];
    }

};
// @lc code=end

