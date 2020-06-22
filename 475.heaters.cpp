/*
 * @lc app=leetcode id=475 lang=cpp
 *
 * [475] Heaters
 */

// @lc code=start
class Solution {
public:
	int bsearch(vector<int>& v, int p) {
		int l = 0, r = v.size();
		while(l < r) {
			int m = l + (r - l) / 2;
			if(v[m] < p) l = m + 1;
			else r = m;
		}
		return l;
	}
    int findRadius(vector<int>& houses, vector<int>& heaters) {	
		sort(heaters.begin(), heaters.end());
		int res = 0;
		for(auto p : houses) {
			int s = bsearch(heaters, p);
			if(s == heaters.size()) {
				res = max(res, p - heaters[s - 1]);
			} else if(s == 0) {
				res = max(res, heaters[s] - p);
			} else {
				res = max(res, min(p - heaters[s - 1], heaters[s] - p));
			}
		}		
		return res;
    }
};
// @lc code=end

