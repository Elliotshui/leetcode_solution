/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		multiset<int> s1, s2;
		vector<int> res;
		set<int> s;
		for(auto n: nums1)	s1.insert(n);
		for(auto n: nums2)  s2.insert(n);
		for(auto n: nums1) {
			if(!s.count(n)) {
				s.insert(n);
				int cnt1 = distance(s1.lower_bound(n), s1.upper_bound(n));
				int cnt2 = distance(s2.lower_bound(n), s2.upper_bound(n));
				for(int i = 0; i < min(cnt1, cnt2); ++i) {
					res.push_back(n);
				}
			}
		}
		return res;
    }
};
// @lc code=end

