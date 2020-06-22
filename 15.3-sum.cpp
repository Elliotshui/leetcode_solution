/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        vector< vector<int> > result;
        sort(nums.begin(), nums.end());
        int i, sz = nums.size();
        for(i = 0; i < sz; ++i) {
            int j = i + 1, k = sz - 1;
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    while(j < k && nums[j] == nums[j + 1]) j++;
                    while(k > j && nums[k] == nums[k - 1]) k--;
                    j++;
                    k--;
                }
                else if(sum > 0) k--;
                else j++;
            }
        }
        return result;
    }
};

