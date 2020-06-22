/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len == 0) return 0;
        int res = 1;
        int l = 0;
        unordered_map<char, int> cnt;
        cnt[s[0]] = 1;
        for(int r = 1; r < len; ++r) {
            if(cnt.count(s[r]) == 0) cnt[s[r]] = 0;
            cnt[s[r]]++;
            while(l <= r && cnt[s[r]] > 1) {
                if(s[l] == s[r]) cnt[s[r]]--;
                else cnt[s[l]]--;
                l++;
            }
            if(r - l + 1 > res) res = r - l + 1;
        }
        return res;
        
    }
};
// @lc code=end

