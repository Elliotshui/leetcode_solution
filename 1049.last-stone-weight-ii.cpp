/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 */
// 0-1背包动态规划
// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totalstone = 0;
        for(int i = 0; i < stones.size(); ++i) {
            totalstone += stones[i];
        }
        vector<vector<int>> dp(stones.size() + 1, vector<int>(totalstone / 2 + 1, 0));
        for(int i = 1; i < stones.size() + 1; ++i) {
            for(int j = 1; j < totalstone / 2 + 1; ++j) {
                if (j - stones[i - 1] < 0) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j - stones[i - 1]] + stones[i - 1], dp[i - 1][j]);
                }
            }
        }
        return totalstone - 2*dp[stones.size()][totalstone / 2];
    }
};
// @lc code=end

