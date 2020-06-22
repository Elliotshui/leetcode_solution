/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxp, minp, res;
        res = nums[0];
        maxp = nums[0];
        minp = nums[0];

        for(int i = 1; i < nums.size(); ++i) {
            int maxp1 = maxp * nums[i];
            int minp1 = minp * nums[i];
            maxp = max(maxp1, minp1);
            minp = min(maxp1, minp1);
            maxp = max(maxp, nums[i]);
            minp = min(minp, nums[i]);
            if(maxp > res)
                res = maxp;
        }
        return res;
    }
};
// @lc code=end

