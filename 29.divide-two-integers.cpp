/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
		if(dividend == 0) return 0;
		if (dividend == INT_MIN && divisor == -1) return INT_MAX;
		int neg = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0) ? 1 : -1;
		long m = labs(dividend), n = labs(divisor);	
		if(n > m) return 0;
		long l = n, res = 1;
		while(l < m) {
			l = l << 1;
			res = res << 1;
		}
		while(l > m) {
			l -= n;
			res--;
		}
		return neg > 0? res : -res;
    }
};
// @lc code=end

