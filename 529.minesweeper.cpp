/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 */

// @lc code=start
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		if(board.size() == 0) return board;
		int c = board.size(), r = board[0].size();
		queue<pair<int, int>> q;
		vector<vector<bool>> v(c, vector<bool>(r, false));
		q.push(make_pair(click[0], click[1]));	
		int d[8][2] = {{0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {1, 0}, {-1, 0}};
		while(!q.empty()) {
			auto f = q.front(); q.pop();
			int x = f.first, y = f.second;
			if(board[x][y] == 'M') {
				board[x][y] = 'X';
				return board;
			}
			int mcnt = 0;
			for(int i = 0; i < 8; ++i) {
				int x1 = x + d[i][0], y1 = y + d[i][1];
				if(x1 >= 0 && x1 < c && y1 >= 0 && y1 < r && board[x1][y1] == 'M') mcnt++; 
			}
			if(mcnt == 0) {
				board[x][y] = 'B';
				for(int i = 0; i < 8; ++i) {
					int x1 = x + d[i][0], y1 = y + d[i][1];
					if(x1 >= 0 && x1 < c && y1 >= 0 && y1 < r && v[x1][y1] == false) {
						q.push(make_pair(x1, y1));
						v[x1][y1] = true;
					} 
				}
			} else {
				board[x][y] = '0' + mcnt;
			}
		}
		return board;
    }
};
// @lc code=end

