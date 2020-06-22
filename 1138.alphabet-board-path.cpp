/*
 * @lc app=leetcode id=1138 lang=cpp
 *
 * [1138] Alphabet Board Path
 */

// @lc code=start
class Solution {
public:
    string alphabetBoardPath(string target) {
        int p = 0;
        stringstream s;
        for(int i = 0; i < target.length(); ++i) {
            char t = target[i] - 'a';
            while(p != t) {
                if(t == 25) {
                    while(p % 5 > 0) {
                        p--;
                        s << 'L';
                    }
                }
                if(t / 5 > p / 5) {
                    p += 5;
                    s << 'D';
                } else if (t / 5 < p / 5) {
                    p -= 5;
                    s << 'U';
                } else if (t % 5 > p % 5) {
                    p += 1;
                    s << 'R';
                } else if (t % 5 < p % 5) {
                    p -= 1;
                    s << 'L';
                } 
            }
            s << '!';
        }
        return s.str();
    }
};
// @lc code=end

