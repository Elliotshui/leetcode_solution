/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> tmp;
		helper(k, 0, n, 0, tmp, res);
		return res;
    }
	void helper(int k, int c, int n, int j, vector<int>&tmp, vector<vector<int>>& res) {
		if(c == k) {
			res.push_back(tmp);
			return;
		}
		for(int i = j + 1; i <= n - k + c + 1; ++i) {
			tmp.push_back(i);
			helper(k, c + 1, n, i, tmp, res);
			tmp.pop_back();
		}
	}
};
// @lc code=end

