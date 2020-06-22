/*
 * @lc app=leetcode id=667 lang=cpp
 *
 * [667] Beautiful Arrangement II
 */

// @lc code=start
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        for(int i = 0; i < n - k; ++i) {
            res.push_back(i + 1);
        }
        int delta = k, sign = 1;
        while(delta > 0) {
            res.push_back(res.back() + delta * sign);
            sign = -sign;
            delta--;
        }
        return res;
    }
};
// @lc code=end

