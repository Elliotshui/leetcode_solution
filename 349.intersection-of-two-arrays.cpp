/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> s;
		set<int> res_set;
		vector<int> res;
		for(auto n : nums1) s.insert(n);
		for(auto n : nums2) {
			if(s.count(n) && !res_set.count(n)) {
				res_set.insert(n);
				res.push_back(n);
			}
		}
		return res;
    }
};
// @lc code=end

