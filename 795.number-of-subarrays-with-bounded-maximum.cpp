/*
 * @lc app=leetcode id=795 lang=cpp
 *
 * [795] Number of Subarrays with Bounded Maximum
 */

// @lc code=start
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
		return helper(A, L, R, 0, A.size());	
    }
	int helper(vector<int>& A, int L, int R, int left, int right) {
		int maxA = -1, maxp = -1;
		int res = 0;
		for(int i = left; i < right; ++i) {
			if(A[i] > maxA) { 
				maxA = A[i];
				maxp = i;
			}
		}
		if(maxA <= R && maxA >= L) {
			res = (maxp - left + 1) * (right - maxp);
			res += helper(A, L, R, left, maxp) + helper(A, L, R, maxp + 1, right);
		} else if(maxA > R) {
			res += helper(A, L, R, left, maxp) + helper(A, L, R, maxp + 1, right);
		}
		return res;
	}
};
// @lc code=end

