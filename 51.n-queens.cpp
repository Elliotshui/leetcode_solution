/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
		vector<vector<char>> board(n, vector<char>(n, '.'));
		vector<vector<string>> res;
		helper(0, n, board, res);
		return res;
    }
	void helper(int c, int n, vector<vector<char>>& board, vector<vector<string>> &res) {
		if(c == n) {
			vector<string> board_string;
			for(int i = 0; i < n; ++i) {
				string tmp = "";
				for(int j = 0; j < n; ++j) {
					tmp += board[i][j];
				}
				board_string.push_back(tmp);
			}	
			res.push_back(board_string);
			return;
		}
		for(int j = 0; j < n; ++j) {
			board[c][j] = 'Q'; 
			bool valid = true;
			for(int i = 0; i < c; ++i) {
				if(board[i][j] == 'Q' || (j - c + i >= 0 && board[i][j - c + i] == 'Q') || (j + c - i < n && board[i][j + c - i] == 'Q')) {
					valid = false;	
					break;
				}
			}
			if(valid) helper(c + 1, n, board, res);
			board[c][j] = '.';
		}
	}
};
// @lc code=end

