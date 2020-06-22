/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 */

// @lc code=start

// 双指针法
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int l = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for(int i = 0; i < l; ++i) {
            for(int j = i + 1; j < l; ++j) {
                for(int k = j + 1; k < l; ++k) {
                    if(nums[i] + nums[j] > nums[k])
                        cnt++;
                    else 
                       break;
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

