/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
    int maxProfit_s(vector<int>& prices, int s, int e) {
        if(s == e)
            return 0;
        int res = 0;
        int min_price = prices[s];
        for(int i = s + 1; i < e; ++i) {
            if(prices[i] - min_price > res)
                res = prices[i] - min_price;
            if(min_price > prices[i])
                min_price = prices[i];
        }
        return res;
    }
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if(sz == 0)
            return 0;
        int res = maxProfit_s(prices, 0, sz);
        if(res == 0)
            return 0;
        for(int i = 2; i <= sz - 2; ++i) {
            int total = maxProfit_s(prices, 0, i) + maxProfit_s(prices, i, sz);
            if(total > res)
                res = total;
        }
        return res;
    }
};
// @lc code=end

