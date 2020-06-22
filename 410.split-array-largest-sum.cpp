/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
		vector<vector<long>> dp(m + 1, vector<long>(nums.size() + 1, LONG_MIN));
		// calculate sum vector
		vector<long> sum;
		long s = 0;
		sum.push_back(0);
		for(auto n : nums) {
			s += n;
			sum.push_back(s);
		}
		// dp
    for(int i = 1; i <= nums.size(); ++i) {
        dp[1][i] = sum[i] * 2;
    }
    for(int i = 1; i <= nums.size(); ++i) {
        for(int sp = 2; sp <= m; ++sp) {
            int p = bs(dp[sp - 1], i, sum[i]);
            if(p == i && dp[sp - 1][i - 1] >= 0) dp[sp][i] = sum[i] - sum[i - 1];
            else if(p < i) {
                dp[sp][i] = min(dp[sp - 1][p] - sum[p], (p > 0 ?  sum[i] - sum[p - 1]: LONG_MAX));
            }
            dp[sp][i] += sum[i];
        }
    }
    return dp[m][nums.size()] - sum[nums.size()];;
    }
	int bs(vector<long>& v, int end, long t) {
		int l = 0, r = end;
		while(l < r) {
			int m = (l + r) / 2;
			if(v[m] >= t) r = m;
			else l = m + 1;
		}
		return l;
	}
};
// @lc code=end

