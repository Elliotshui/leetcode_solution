/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
		if(n == 0) return 1;
		long m = labs(n);
		double res = pow(x, m);	
		return n >= 0 ? res : (1 / res);
    }
	double pow(double x, long m) {
		if(m == 0) return 1;
		double res = pow(x, m / 2);
		int div = m % 2;
		res *= res;
		if(div == 1) res *= x;
		return res; 
	}
};
// @lc code=end

