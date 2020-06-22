/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */
//递推, 把所有排列分为n个子序列, 确定k在第几个子序列. 之后对n - 1和k % (n - 1)!进行归纳:w

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
		vector<int> nums;
		for(int i = 0; i < n; ++i) {
			nums.push_back(i + 1);
		}
		vector<int> jc;
		jc.push_back(1);
		for(int i = 1; i <= n; ++i) {
			jc.push_back(jc.back() * i);
		}
		k = k - 1;
		string res = "";
		for(int i = 0; i < n; ++i) {
			int rank = k / jc[n - i - 1];
			k = k % jc[n - i - 1];
			int cnt = 0, j;
			for(j = 0; j < n; ++j) {
				if(nums[j] != 0) cnt++;
				if(cnt > rank) break;
			}
			res += '0' + nums[j];
			nums[j] = 0;
		}
		return res;
    }
};
// @lc code=end

