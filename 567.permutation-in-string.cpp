/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
		unordered_map<char, int> cnt;
		int len1 = s1.length(), len2 = s2.length();
		for(int i = 0; i < len1;++i) {
			cnt[s1[i]]++;
		}
		int l = 0; 
		unordered_map<char, int> cntl;
		int t = 0;
		for(int r = 0; r < len2; ++r) {
			char c = s2[r];
			cntl[c]++;
			while(cnt[c] < cntl[c] && l <= r) {
				cntl[s2[l]]--;
				l++;
			}
			if(r - l + 1 == len1) return true;
		}
		return false;
    }
};
// @lc code=end

