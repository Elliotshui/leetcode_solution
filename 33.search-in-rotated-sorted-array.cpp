/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int m = (l + r)/2;
            if(nums[m] == target) return m;
            if(nums[m] < nums[r]) {
                if(nums[m] < target && nums[r] >= target) l = m + 1;
                else r = m - 1;
            }
            else {
                if(nums[m] > target && nums[l] <= target) r = m - 1;
                else l = m + 1;
            }
        }
        return -1;
    }
};

