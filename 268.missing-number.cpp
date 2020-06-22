/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
// 利用异或的性质
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n;
        for(int i = 0; i < n; ++i) {
            res = res ^ nums[i] ^ i;
        }
        return res;
    }
};
// @lc code=end

