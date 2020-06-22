/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = -1, sz = nums.size();
        for(int i = 0; i < sz; ++i) {
            if(j < 0 || nums[i] != nums[j]) {
                ++j;
                nums[j] = nums[i];
            }
        }
        return j + 1;
    }
};

