/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		multiset<int> low;
		for(auto n : nums) {
			auto j = low.lower_bound(n);
			if(j == low.end()) low.insert(n);
			else {
				low.erase(j);
				low.insert(n);
			}
		}
		return low.size();
    }
};
// @lc code=end

