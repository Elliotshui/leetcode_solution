/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
		long n = num, l = 0, r = n + 1;
		while(l < r) {
			long m = (l + r) / 2;
			if(m * m == n) return true;
			if(m * m < n) l = m + 1;
			else r = m;
		}
		return false;
    }
};
// @lc code=end

