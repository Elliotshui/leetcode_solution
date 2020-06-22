/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 */

// @lc code=start
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
		if(n == 0) return 1;
		long cnt = 10;
		long mul = 9;
		for(int i = 1; i < n; i++) {
			mul *= (10 - i);
			cnt = cnt + mul;	
		}
		return cnt;
    }
};
// @lc code=end

