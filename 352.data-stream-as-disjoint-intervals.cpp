/*
 * @lc app=leetcode id=352 lang=cpp
 *
 * [352] Data Stream as Disjoint Intervals
 */

// @lc code=start
class SummaryRanges {
public:
    /** Initialize your data structure here. */
	struct Range{
		int lower;
		int upper;
		Range(int l, int u):lower(l), upper(u) {}
		bool operator < (const Range &r) const {
			return lower < r.lower;
		}
	};
	set<Range> s;
    SummaryRanges() {
    }
    void addNum(int val) {
		Range i = Range(val, val);
		auto r = s.upper_bound(i); 
		auto l = r;
		if(r != s.begin()) {
			l--;
			if(val <= l->upper) return;
			if(val == l->upper + 1) {
				i = Range(l->lower, i.upper);
				s.erase(l);
			} 
		}
		if(r != s.end()) {
			if(val == r->lower - 1) {
				i = Range(i.lower, r->upper);
				s.erase(r);
			}
		} 
		s.insert(i);
		return;
    }
    
    vector<vector<int>> getIntervals() {
		vector<vector<int>> res;
		for(auto i = s.begin(); i != s.end(); i++) {
			res.push_back(vector<int>{i->lower, i->upper});
		}
		return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end

