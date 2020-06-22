/*
 * @lc app=leetcode id=436 lang=cpp
 *
 * [436] Find Right Interval
 */

// @lc code=start
class Solution {
public:
	struct Interval {
		int l, r, idx;
		Interval(int _l, int _r, int _i): l(_l), r(_r), idx(_i) {}
		bool operator < (const Interval& i) const {
			return l < i.l;
		}
	};
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
		int sz = intervals.size();
		vector<int> res(sz, -1);
		set<Interval> s;
		for(int i = 0; i < sz; ++i) s.insert(Interval(intervals[i][0], intervals[i][1], i)); 
		for(int i = 0; i < sz; ++i) {
			auto p = s.lower_bound(Interval(intervals[i][1], 0, i));
			if(p != s.end()) res[i] = p->idx;
		}
		return res;
    }
};
// @lc code=end

