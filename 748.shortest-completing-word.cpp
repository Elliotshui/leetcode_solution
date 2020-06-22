/*
 * @lc app=leetcode id=748 lang=cpp
 *
 * [748] Shortest Completing Word
 */

// @lc code=start
class Solution {
public:
    int rank(char a) {
        if(a <= 'Z' && a >= 'A')
            return a - 'A';
        else if(a <= 'z' && a >= 'a') 
            return a - 'a';
        else return -1;
    }

    void count(vector<int>& cnt, string& s) {
        for(int i = 0; i < s.length(); ++i) {
            int r = rank(s[i]);
            if(r >= 0)
                cnt[r]++;
        }
        return;
    }
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> cnt(26, 0);
        count(cnt, licensePlate);
        string res;
        int min_len = 1001;
        for(int i = 0; i < words.size(); ++i) {
            vector<int> tmp(26, 0);
            count(tmp, words[i]);
            bool flag = true;
            for(int j = 0; j < 26; ++j) {
                if(tmp[j] < cnt[j])
                   flag = false;
            }
            if(flag && words[i].length() < min_len) {
                res = words[i];
                min_len = words[i].length();
            }
        }
        return res;
    }
};
// @lc code=end

