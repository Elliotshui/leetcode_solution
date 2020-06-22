/*
 * @lc app=leetcode id=786 lang=cpp
 *
 * [786] K-th Smallest Prime Fraction
 */

// @lc code=start
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
		sort(A.begin(), A.end());
		vector<vector<pair<int, int>>> fractions;
		int sz = A.size();
		for(int i = 0; i < sz - 1; ++i) {
			vector<pair<int, int>> tmp;
			for(int j = sz - 1; j > i; --j) {
				tmp.push_back(make_pair(A[i], A[j]));
			}
			fractions.push_back(tmp);
		}
		double l = 0.0, r = 1.0;
		while(1) {
			double m = (l + r) / 2;
			double next_greater_value = 1.0;
			pair<int, int> next_greater;
			int cnt = 0;
			for(int i = 0; i < sz - 1; ++i) {
				int less_cnt = bsearch(m, fractions[i]);
				if(less_cnt < fractions[i].size()) {
					double val = (double) fractions[i][less_cnt].first / fractions[i][less_cnt].second;		
					if(val < next_greater_value) {
						next_greater_value = val;
						next_greater = fractions[i][less_cnt];
					}
				}
				cnt += less_cnt;
			}
			if(cnt == K - 1) return vector<int>{next_greater.first, next_greater.second};
			else if(cnt < K - 1) l = m;
			else r = m;
		}
    }
	int bsearch(double p, vector<pair<int, int>> &v) {
		int l = 0, r = v.size();
		while(l < r) {
			int m = l + (r - l) / 2;
			double q = (double)v[m].first / v[m].second;
			if(q > p) r = m;
			else l = m + 1;
		}
		return l;
	}
};
// @lc code=end

