/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int min_sum = 0, max_delta = -INT_MAX;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int delta = sum - min_sum;
            if(delta > max_delta)
                max_delta = delta;
            if(sum < min_sum)
                min_sum = sum;
        }
        return max_delta;
    }
};

