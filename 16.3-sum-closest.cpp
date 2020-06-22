/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 * 
 * 双指针法筛除不符合条件的pair
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i, closest_sum = INT_MAX / 2, sz = nums.size();        
        for(i = 0; i < sz; ++i) {
            int j = i + 1;
            int k = sz - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target)
                    return target;
                else {
                    if(abs(sum - target) < abs(closest_sum - target))
                        closest_sum = sum;
                    if(sum < target) j++;
                    else k--;
                }
            }
        }
        return closest_sum;
    }
};

