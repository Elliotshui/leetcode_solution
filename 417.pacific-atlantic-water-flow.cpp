/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<vector<int>> res;
		if(matrix.size() == 0) return res;
		int c = matrix.size(), r = matrix[0].size();

		// can reach pacific
		vector<vector<bool>> v1(c, vector<bool>(r, false));	
		queue<pair<int, int>> q1;
		for(int j = 0; j < r; ++j) {
			v1[0][j] = true;
			q1.push(make_pair(0, j));	
		}
		for(int i = 1; i < c; ++i) {
			v1[i][0] = true;
			q1.push(make_pair(i, 0));
		}
		bfs(q1, v1, matrix);

		// can reach atlantic
		vector<vector<bool>> v2(c, vector<bool>(r, false));	
		queue<pair<int, int>> q2;
		for(int j = 0; j < r; ++j) {
			v2[c - 1][j] = true;
			q2.push(make_pair(c - 1, j));
		}
		for(int i = 0; i < c - 1; ++i) {
			v2[i][r - 1] = true;
			q2.push(make_pair(i, r - 1));
		}
		bfs(q2, v2, matrix);

		// can reach both
		for(int i = 0; i < c; ++i) {
			for(int j = 0; j < r; ++j) {
				if(v1[i][j] && v2[i][j]) {
					res.push_back({i, j});
				}
			}
		}
		return res;
    }

	void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& v, vector<vector<int>>& m) {
		int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		while(!q.empty()) {
			auto &curr = q.front();
			for(int i = 0; i < 4; ++i) {
				int x1 = curr.first + d[i][0], y1 = curr.second + d[i][1];
				if(x1 >= 0 && x1 < m.size() && y1 >= 0 && y1 < m[0].size() && !v[x1][y1] && m[x1][y1] >= m[curr.first][curr.second]) {
					q.push(make_pair(x1, y1));
					v[x1][y1] = true;
				}
			}	
			q.pop();
		}
		return;
	}
};
// @lc code=end

