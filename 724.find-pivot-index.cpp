/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        vector<int> sums(nums.size() + 1, 0);
        sums[0] = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            sums[i + 1] = sum;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(sums[i] == sums.back() - sums[i + 1])
                return i;
        }
        return -1;
    }
};
// @lc code=end

