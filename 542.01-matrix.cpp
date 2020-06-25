/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		if(matrix.size() == 0) return vector<vector<int>>();
		int c = matrix.size(), r = matrix[0].size();
		vector<vector<int>> res(c, vector<int>(r, -1));
		queue<pair<int, int>> q;
		int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		for(int i = 0; i < c; ++i) {
			for(int j = 0; j < r; ++j) {
				if(matrix[i][j] == 0) {
					q.push(make_pair(i, j));
					res[i][j] = 0;
				}
			}
		}
		while(!q.empty()) {
			auto f = q.front(); q.pop();
			int x = f.first, y = f.second;
			for(int i = 0; i < 4; ++i) {
				int x1 = x + d[i][0], y1 = y + d[i][1];
				if(x1 >= 0 && x1 < c && y1 >= 0 && y1 < r && res[x1][y1] == -1) {
					q.push(make_pair(x1, y1));
					res[x1][y1] = res[x][y] + 1;
				}
			}
		}
		return res;
    }
};
// @lc code=end

