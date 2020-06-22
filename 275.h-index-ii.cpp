/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
		int sz = citations.size();
		int l = 0, r = sz;
		while(l < r) {
			int m = (l + r) / 2;
			if(citations[m] + m < sz) l = m + 1;
			else r = m;
		}
		return sz - r;
    }
};
// @lc code=end

