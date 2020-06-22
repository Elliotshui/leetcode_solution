/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int len = 1, max_len = 1;
        for(int i = 1; i < nums.size(); ++i) {
            len = nums[i] > nums[i - 1] ? len + 1 : 1;
            if(len > max_len) max_len = len;
        }
        return max_len;
    }
};
// @lc code=end

