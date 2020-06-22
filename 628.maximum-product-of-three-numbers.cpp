/*
 * @lc app=leetcode id=628 lang=cpp
 *
 * [628] Maximum Product of Three Numbers
 */

// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int res = -__INT32_MAX__, tmp;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; ++i) {
            if(nums[i] == 0) tmp = 0;
            else if(nums[i] > 0) {
                tmp = nums[i] * max(nums[i + 1] * nums[i + 2], max(nums[nums.size() - 1] * nums[nums.size() - 2], nums[i + 1] * nums[nums.size() - 1]));
            }
            else {
                tmp = nums[i] * min(nums[i + 1] * nums[i + 2], min(nums[nums.size() - 1] * nums[nums.size() - 2], nums[i + 1] * nums[nums.size() - 1]));
            }
            if(tmp > res)   res = tmp;
        }
        return res;
    }
};
// @lc code=end

