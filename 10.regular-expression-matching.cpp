/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
	struct re {
		int type; //0 for single, 1 for multiple
		char c;
		re(int t_, int c_): type(t_), c(c_) {}
	};
    bool isMatch(string s, string p) {
		int ls = s.length(), lp = p.length();
		// parse regular expression
		vector<re> pre;
		for(int i = 0; i < lp;) {
			char t = p[i];
			if(i == lp - 1) {
				pre.push_back(re(0, t));
			}
			else {
				char n = p[i + 1];
				if(n == '*') {
					pre.push_back(re(1, t));
					i++;
				} else {
					pre.push_back(re(0, t));
				}
			}
			i++;
		}
		// dp
		int lre = pre.size();
		vector<vector<bool>> dp(ls + 1, vector<bool>(lre + 1, false));
		dp[0][0] = true;
		for(int j = 1; j <= lre; ++j) {
			dp[0][j] = pre[j - 1].type == 1 ? dp[0][j - 1] : false;
		}
		for(int i = 1; i <= ls; ++i) {
			for(int j = 1; j <= lre; ++j) {
				int type = pre[j - 1].type;
				char c = pre[j - 1].c;
				char t = s[i - 1];
				
				if(type == 0) {
					if(c == '.' || c == t) dp[i][j] = dp[i - 1][j - 1];
					else dp[i][j] = false;
				}
				else {
					dp[i][j] = dp[i][j - 1];
					int k = i - 1;
					while(dp[i][j] == false && k >= 0) {
						if(c == '.' || c == s[k]) {
							dp[i][j] = dp[i][j] || dp[k][j - 1];
							k--;	
						}
						else break;
					}
				}
			}
		}
		return dp[ls][lre];
    }
};
// @lc code=end

