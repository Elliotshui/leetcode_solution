/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
		int sl = s.length(), tl = t.length();
		int cnt = 0;
		for(int i = 0; i < tl; ++i) {
			if(t[i] == s[cnt]) {
				cnt++;
			}
		}		
		return cnt == sl;
    }
};
// @lc code=end

