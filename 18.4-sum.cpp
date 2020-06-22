/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */
class Solution {
public:

    vector<vector<int>> threesum(vector<int>& nums, int start, int target) {
        int i, sz = nums.size();
        vector<vector<int>> result;
        for(i = start; i < sz; ++i) {
            int j = i + 1, k = sz - 1;
            if(i > start && nums[i] == nums[i - 1]) continue;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    while(j < k && nums[j] == nums[j + 1]) j++;
                    while(j < k && nums[k] == nums[k - 1]) k--;
                    j++;
                    k--;
                }
                else if(sum < target) j++;
                else k--;
            }
        }
        return result;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i, sz = nums.size();
        vector<vector<int>> result;
        for(i = 0; i < sz; ++i) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            vector<vector<int>> triplet = threesum(nums, i + 1, target - nums[i]);
            for(int j = 0; j < triplet.size(); ++j) {
                triplet[j].push_back(nums[i]);
                result.push_back(triplet[j]);
            }
        }
        return result;
    }
};

