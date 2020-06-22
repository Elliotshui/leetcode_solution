/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if(sz == 0) return 0;
        int min_price = prices[0];
        int res = 0;
        for(int i = 1; i < sz; ++i) {
            if(prices[i] - min_price > res)
                res = prices[i] - min_price;
            min_price = min(min_price, prices[i]);
        }
        return res;
    }
};
// @lc code=end

