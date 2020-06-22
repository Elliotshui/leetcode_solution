/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 */

// @lc code=start
class Solution {
public:
	int res;
	vector<int> nums;
    int countArrangement(int N) {
		res = 0;
		for(int i = 1; i <= N; ++i) nums.push_back(i);
		helper(0, N);
		return res;
    }
	void helper(int cnt, int N) {
		if(cnt == N) {
			res++;
			return;
		}
		for(int i = 0; i < N; ++i) {
			if(nums[i] != 0 && (nums[i] % (cnt + 1) == 0 || (cnt + 1) % nums[i] == 0)) {
				nums[i] = 0;
				helper(cnt + 1, N);
				nums[i] = i + 1;
			}
		}
	}
};
// @lc code=end

