/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
	void helper(vector<int>& nums, vector<bool> &used, vector<int>& tmp, vector<vector<int>>& res) {
		bool all_used = true;
		for(int i = 0; i < nums.size(); ++i) {
			if(!used[i]) {
				all_used = false;
				tmp.push_back(nums[i]);
				used[i] = true;
				helper(nums, used, tmp, res);
				tmp.pop_back();
				used[i] = false;
			}
		}
		if(all_used) res.push_back(tmp);
		return;
	}
    vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		vector<bool> used(nums.size(), false);
		vector<int> tmp;
		helper(nums, used, tmp, res);
		return res;
    }
};
// @lc code=end

