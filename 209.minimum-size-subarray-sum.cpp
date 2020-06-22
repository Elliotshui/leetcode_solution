/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
// 双指针
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = 1, sz = nums.size();
        if(sz == 0) return 0;
        int sum = nums[0], min = sz + 1;
        while(l < sz) {
            while(sum < s && r < sz) {
                sum += nums[r];
                r++;
            }
            if(sum >= s && r - l < min) {
                min = r - l;
            }
            sum -= nums[l];
            l++;
        }
        return min == sz + 1? 0: min;
    }
};
// @lc code=end

