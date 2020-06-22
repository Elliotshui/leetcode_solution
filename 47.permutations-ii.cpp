/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
	void helper(vector<int>& nums, vector<bool> &used, vector<int>& tmp, vector<vector<int>>& res) {
		bool all_used = true;
		int last = nums[0] - 1;
		for(int i = 0; i < nums.size(); ++i) {
			if(!used[i] && nums[i] != last) {
				all_used = false;
				tmp.push_back(nums[i]);
				used[i] = true;
				helper(nums, used, tmp, res);
				tmp.pop_back();
				used[i] = false;
				last = nums[i];
			}
		}
		if(all_used) res.push_back(tmp);
		return;
	}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		vector<bool> used(nums.size(), false);
		vector<int> tmp;
		helper(nums, used, tmp, res);
		return res;      
    }
};
// @lc code=end

