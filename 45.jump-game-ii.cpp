/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int sz = nums.size();
        int p = 0, jumps = 0;
        while(p < sz - 1) {
            int maxp = p, nextp = p;
            for(int i = 1; i <= nums[p]; ++i) {
                if(p + i == sz - 1) {
                    jumps += 1;
                    p = sz - 1;
                    return jumps;
                }
                else {
                    if(p + i + nums[p + i] > maxp) {
                        nextp = p + i;
                        maxp = p + i + nums[p + i];
                    }
                }
            }
            p = nextp;
            jumps += 1;
        }
        return jumps;
    }
};

