/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m1 = -1, m2 = -1, m;
        while(l <= r) {
            m = (l + r) / 2;
            if(nums[m] < target)
                l = m + 1;
            else if(nums[m] > target)
                r = m - 1;
            else {
                m1 = m;
                r = m - 1;
            }
        }
        l = 0;
        r = nums.size() - 1;
        while(l <= r) {
            m = (l + r) / 2;
            if(nums[m] < target)
                l = m + 1;
            else if(nums[m] > target)
                r = m - 1;
            else {
                m2 = m;
                l = m + 1;
            }
        }
        vector<int> result;
        result.push_back(m1);
        result.push_back(m2);
        return result;
    }
};

