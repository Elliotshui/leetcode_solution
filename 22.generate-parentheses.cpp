/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> res;
		if(n ==  0) {
			res.push_back("");
			return res;
		}
		for(int i = 1; i <= n; ++i) {
			vector<string> tmp1 = generateParenthesis(n - i);
			vector<string> tmp2 = generateParenthesis(i - 1);
			for(int j = 0; j < tmp2.size(); ++j) {
			for(int k = 0; k < tmp1.size(); ++k) {
				res.push_back('(' + tmp2[j] + ')' + tmp1[k]);
			}
			}
		}
		return res;
    }
};
// @lc code=end

