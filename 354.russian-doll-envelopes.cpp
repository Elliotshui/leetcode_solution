/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
// 对w升序排列, 对h降序排列, 求h的最大上升子序列
// 最大上升子序列求法: low数组加二分, low数组表示长度为k的子序列的最小值
class Solution {
public:
	struct E {
		int w, h;
		E(int _w, int _h): w(_w), h(_h) {}
		bool operator < (const E& e) const {
			return w < e.w || (w == e.w && h > e.h);
		}
	};
    int maxEnvelopes(vector<vector<int>>& envelopes) {
		int sz = envelopes.size();
		set<E> s;
		for(auto e : envelopes) s.insert(E(e[0], e[1]));
		multiset<int> low;
		for(auto i = s.begin(); i != s.end(); i++) {
			auto j = low.lower_bound(i->h);
			if(j == low.end()) low.insert(i->h);
			else {
				low.erase(j);
				low.insert(i->h);	
			}
		}
		return low.size();
    }
};
// @lc code=end

