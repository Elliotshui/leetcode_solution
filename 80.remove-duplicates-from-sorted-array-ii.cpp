/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        if(sz <= 2)
            return sz;
        int p = 2;
        for(int i = 2; i < sz; ++i) {
            if(nums[i] != nums[p - 2]) {
                nums[p] = nums[i];
                p++;
            }
        }
        return p;
    }
};

