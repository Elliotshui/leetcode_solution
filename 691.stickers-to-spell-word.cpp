/*
 * @lc app=leetcode id=691 lang=cpp
 *
 * [691] Stickers to Spell Word
 */

// @lc code=start
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
		int t = target.length();
		vector<int> dp(1 << t, -1);
		dp[0] = 0;
		for (int i = 0; i < (1 << t); ++i) {
			for(auto& s: stickers) {
				int curr = i;
				for(auto & c: s) {
					for(int j = 0; j < t; ++j) {
						if(((curr >> j) & 1) == 1 && target[j] == c) {
							curr = curr & (~(1 << j));
							break;
						}
					}
				}
				dp[i] = dp[curr] == -1 ? dp[i] : (dp[i] == -1 ? dp[curr] + 1 : min(dp[i], dp[curr] + 1));
			}
		}
		return dp[(1 << t) - 1];
    }
};
// @lc code=end

