/*
 * @lc app=leetcode id=788 lang=cpp
 *
 * [788] Rotated Digits
 */

// @lc code=start
class Solution {
public:
    int rotatedDigits(int N) {
		int res = 0;
		for(int i = 1; i <= N; ++i) {
			int x = i, digit;
			bool valid = true, same = true; 
			while(x > 0) {
				digit = x % 10;
				x = x / 10;
				if(digit == 3 || digit == 4 || digit == 7) {
					valid = false;
				}
				if(digit == 2 || digit == 5 || digit == 6 || digit == 9) {
					same = false;
				}
			}	
			if(valid && (!same)) {
				res++;
			}
		}
		return res;
    }
};
// @lc code=end

