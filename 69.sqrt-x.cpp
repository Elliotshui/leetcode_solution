/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
		long l = 0, r = x, t = x;
		while(l < r) {
			long m = l + (r - l + 1) / 2;
			if(m * m == t) return m;
			else if(m * m > t) r = m - 1; 
			else l = m;
		}
		return l;
    }
};
// @lc code=end

