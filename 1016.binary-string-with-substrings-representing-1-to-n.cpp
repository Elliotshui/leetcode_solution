/*
 * @lc app=leetcode id=1016 lang=cpp
 *
 * [1016] Binary String With Substrings Representing 1 To N
 */

// @lc code=start
class Solution {
public:
    bool queryString(string S, int N) {
        unordered_set<int> s;
        if(N > 2047) return false;
        for(int i = 0; i < S.length(); ++i) {
            int ans = 0;
            for(int j = 0; j < 32 && (i + j) < S.length(); ++j) {
                ans = ans << 1;
                ans += S[i + j] - '0';
                s.insert(ans);
            }
        }
        for(int i = 1; i <= N; ++i) {
            if(s.count(i) == 0) 
                return false;
        }
        return true;
    }
};
// @lc code=end

