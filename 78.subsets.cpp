/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */
class Solution {
public:
    vector<vector<int>> subsets_i(vector<int>& nums, int i) {
        vector<vector<int>> result;
        if(i == nums.size()) {
            vector<int> tmp;
            result.push_back(tmp);
            return result;
        }
        result = subsets_i(nums, i + 1);
        int sz= result.size();
        for(int j = 0; j < sz; ++j) {
            result.push_back(result[j]);
            result[j].push_back(nums[i]);
        }
        return result;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        return subsets_i(nums, 0);
    }
};

