/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcnt = 0, cnt = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != 1) {
                cnt = 0;
            }
            else {
                cnt++;
                if(cnt > maxcnt) maxcnt = cnt;
            }
        }
        return maxcnt;
    }
};
// @lc code=end

