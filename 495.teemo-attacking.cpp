/*
 * @lc app=leetcode id=495 lang=cpp
 *
 * [495] Teemo Attacking
 */

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.empty()) return 0;
        int d = 0;
        for(int i = 0; i < timeSeries.size() - 1; ++i) {
            d += min(timeSeries[i + 1] - timeSeries[i], duration);
        }
        d += duration;

        return d;
    }
};
// @lc code=end

