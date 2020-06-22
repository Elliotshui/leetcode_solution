/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
		vector<string> split;
		vector<vector<string>> res;	
		helper(s, res, split, 0);
		return res;
    }
	void helper(string s, vector<vector<string>>& res, vector<string> &split, int p) {
		if (p == s.length()) {
			res.push_back(split);
			return;
		}
		for(int i = p + 1; i <= s.length(); ++i) {
			string tmp = s.substr(p, i - p);
			if(isValid(tmp)) {
				split.push_back(tmp);
				helper(s, res, split, i);	
				split.pop_back();
			}
		}
	}
	bool isValid(string s) {
		for(int i = 0; i < s.length() / 2; ++i) {
			if(s[i] != s[s.length() - i - 1]) return false;
		}
		return true;
	}
};
// @lc code=end

