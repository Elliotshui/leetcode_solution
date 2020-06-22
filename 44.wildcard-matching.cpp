/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
		int ls = s.length(), lp = p.length();
		vector<vector<bool>> dp(ls + 1, vector<bool>(lp + 1, false));
		dp[0][0] = true;	
		for(int i = 0; i <= ls; ++i) {
			for(int j = 1; j <= lp; ++j) {
				char d = p[j - 1];
				if(i == 0) {
					if(d == '*') dp[i][j] = dp[i][j - 1];
					else dp[i][j] = false;
					continue;
				}
				if(d == '*') {
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
				} else if(d == '?') {
					dp[i][j] = dp[i - 1][j - 1];
				} else {
					dp[i][j] = (d == s[i - 1]) ? dp[i - 1][j - 1] : false;
				}
			}
		}
		return dp[ls][lp];
    }
};
// @lc code=end

