/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 * 
 * 三路快排. 比1小的放在左边, 比1大的放在右边. 大一点的元素交换后没有和1比较, 因此需要i--.
 */
class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        return;
    }
    void sortColors(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0)
            return;
        int l = 0, r = sz - 1;
        for(int i = 0; i <= r; ++i) {
            if(nums[i] == 0) {
                swap(nums, i, l);
                l++;
            }
            else if(nums[i] == 2) {
                swap(nums, i, r);
                r--;
                i--;
            }
        }
        return;
    }
};

