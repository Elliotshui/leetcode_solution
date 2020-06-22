/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 */

// @lc code=start
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int m = -1, m_pos = -1, n = -1;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > m) {
                n = m;
                m = nums[i];
                m_pos = i;
            }
            else if(nums[i] > n) {
                n = nums[i];
            }
        }
        if(m >= n*2)
            return m_pos;
        else
            return -1;
          
    } 
};
// @lc code=end

