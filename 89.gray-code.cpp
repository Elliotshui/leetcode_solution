/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */
// 找规律, 改变最高位后低位按之前的顺序回退
// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
		if(n == 0) return vector<int>{0};
		vector<int> res{0, 1};
		for(int i = 1; i < n; ++i) {
			int back = res.size() - 1;
			for(int j = back; j >= 0; --j) {
				res.push_back(res[j] + (1 << i));
			}
		}
		return res;
    }
};
// @lc code=end

