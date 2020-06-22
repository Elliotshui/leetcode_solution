/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
		long l = 0, r = n;
		while(l < r) {
			long m = (l + r) / 2;
			bool bad = isBadVersion(m);
			if(bad) r = m ;
			else l = m + 1;
		}
		return r;
    }
};
// @lc code=end

