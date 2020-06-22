/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subset_p(vector<int>& nums, int p) {
        vector<vector<int>> result;
        if(p == nums.size()) {
            vector<int> tmp;
            result.push_back(tmp);
            return result;
        }
        int p1 = p;
        while(p1 < nums.size() && nums[p] == nums[p1]) 
            p1++;
        result = subset_p(nums, p1);
        int sz = result.size();
        for(int i = 0; i < sz; ++i) {
            vector<int> tmp = result[i];
            for(int j = 0; j < p1 - p; ++j) {
                tmp.push_back(nums[p]);
                result.push_back(tmp);
            }
        }
        return result;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return subset_p(nums, 0);
    }
};
// @lc code=end

