/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        vector<int> sums;
        int sum = 0;
        sums.push_back(sum);
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            sums.push_back(sum);
        }
        int max_sum = -__INT32_MAX__;
        for(int i = nums.size(); i - k >= 0; --i) {
            if(sums[i] - sums[i - k] > max_sum)
                max_sum = sums[i] - sums[i - k];
        }
        return ((double) max_sum) / k;
    }
};
// @lc code=end

