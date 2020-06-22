/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
//dp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int maxp = 0, maxc = -(prices[0]);
        for(int i = 1; i < prices.size(); ++i) {

            int p1 = maxc + prices[i] - fee;
            int p2 = maxp;
            int p3 = maxp - prices[i];

            maxp = max(maxp, max(p1, p2));
            maxc = max(maxc, p3);
        }
        return maxp;
    }
};
// @lc code=end

