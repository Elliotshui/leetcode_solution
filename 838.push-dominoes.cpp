/*
 * @lc app=leetcode id=838 lang=cpp
 *
 * [838] Push Dominoes
 */

// @lc code=start
class Solution {
public:
    string pushDominoes(string dominoes) {
        stack<int> s;
        int len = dominoes.length();
        for(int i = 0; i < len + 1; ++i) {
            if(i < len && dominoes[i] == '.')  continue;
            if(i == len || dominoes[i] == 'R') {
                if(s.empty()) s.push(i);
                else if(dominoes[s.top()] == 'R') {
                    for(int j = s.top(); j < i; ++j) {
                        dominoes[j] = 'R';
                    }
                    s.pop();
                    s.push(i);
                }
                else {
                    int r = s.top(); s.pop();
                    while(!s.empty()) {
                        int l = s.top(); s.pop();
                        if(dominoes[l] == 'L') {
                            r = l;
                            continue;
                        }
                        for(int j = l + 1; j < l + (r - l + 1) / 2; ++j) {
                            dominoes[j] = 'R';
                        }
                        for(int j = l + (r - l) / 2 + 1; j < r; ++j) {
                            dominoes[j] = 'L';
                        }
                    }
                    s.push(i);
                }
            }
            else if(dominoes[i] == 'L') {
                if(s.empty()) {
                    for(int j = 0; j < i; ++j) {
                        dominoes[j] = 'L';
                    }
                    s.push(i);
                }
                else if(dominoes[s.top()] == 'L') {
                    for(int j = s.top(); j < i; ++j) {
                        dominoes[j] = 'L';
                    }
                    s.push(i);
                } 
                else {
                    s.push(i);
                }
            }
        }
        return dominoes;
        
    }
};
// @lc code=end

