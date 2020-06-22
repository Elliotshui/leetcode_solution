/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sz = nums.size();
        int p = 0;
        if(sz <= 1)
            return true;
        while(p < sz - 1 && nums[p] != 0) {
            int maxp = p, nextp = p;
            for(int i = 1; i <= nums[p]; ++i) {
                if(p + i == sz - 1) {
                    return true;
                }
                else {
                    if(p + i + nums[p + i] > maxp) {
                        nextp = p + i;
                        maxp = p + i + nums[p + i];
                    }
                }
            }
            p = nextp;
        }
        return false;
    }
};

