/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
		if(board.size() == 0) return;
		vector<vector<int>> bfs(board.size(), vector<int>(board[0].size(), 0));
		for(int i = 0; i < board.size(); ++i) {
			for(int j = 0; j < board[0].size(); ++j) {
				if(i != 0 && i != board.size() - 1 && j != 0 && j != board[0].size() - 1) continue; 
				if(bfs[i][j] != 0 || board[i][j] == 'X') continue;
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				while(!q.empty()) {
					auto &p = q.front();
					if(bfs[p.first][p.second] == 1 || board[p.first][p.second] == 'X') {
						q.pop();
						continue;
					}
					bfs[p.first][p.second] = 1;
					if(p.first + 1 < board.size()) q.push(make_pair(p.first + 1, p.second));
					if(p.first - 1 >= 0) q.push(make_pair(p.first - 1, p.second));
					if(p.second + 1 < board[0].size()) q.push(make_pair(p.first, p.second + 1));
					if(p.second - 1 >= 0) q.push(make_pair(p.first, p.second - 1));
					q.pop();
				}
			}
		}
		for(int i = 0; i < board.size(); ++i) {
			for(int j = 0; j < board[0].size(); ++j) {
				if(board[i][j] == 'O' && bfs[i][j] == 0) board[i][j] = 'X';
			}
		}
    }
};
// @lc code=end

