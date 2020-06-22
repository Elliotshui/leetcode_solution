/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int cnt[26], mincnt[26];
        for(char c = 'a'; c <= 'z'; ++c) {
            mincnt[c - 'a'] = 200;
        }
        for(int i = 0; i < A.size(); ++i) {
            for(char c = 'a'; c <= 'z'; ++c) {
                cnt[c - 'a'] = 0;
            }
            for(int j = 0; j < A[i].length(); ++j) {
                cnt[A[i][j] - 'a']++;
            }
            for(char c = 'a'; c <= 'z'; ++c) {
                if(mincnt[c - 'a'] > cnt[c - 'a']) {
                    mincnt[c - 'a'] = cnt[c - 'a'];
                }
            }
        }
        vector<string> res;
        for(char c = 'a'; c <= 'z'; ++c) {
            for(int i = 0; i < mincnt[c - 'a']; ++i) {
                string s = "";
                s += c;
                res.push_back(s);
            }
        }
        return res;
    }
};
// @lc code=end

