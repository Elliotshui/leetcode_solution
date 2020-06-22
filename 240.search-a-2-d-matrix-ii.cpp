/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int r = matrix.size();
		if(r == 0) return false;
		int c = matrix[0].size();
		int i = 0, j = c - 1;
		while(j >= 0 && i < r) {
			if(matrix[i][j] == target) return true;
			else if(matrix[i][j] > target) j--;
			else i++; 
		}
		return false;
    }
};
// @lc code=end

