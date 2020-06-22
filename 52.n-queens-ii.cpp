/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
		vector<vector<char>> board(n, vector<char>(n, '.'));
		int res = 0;
		helper(0, n, board, res);
		return res;
    }
	void helper(int c, int n, vector<vector<char>>& board, int &res) {
		if(c == n) {
			res++;
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

