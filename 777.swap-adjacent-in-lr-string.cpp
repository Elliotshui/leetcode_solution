/*
 * @lc app=leetcode id=777 lang=cpp
 *
 * [777] Swap Adjacent in LR String
 */

// @lc code=start
class Solution {
public:

    bool canTransform(string start, string end) {
        int i = 0, j = 0;
        while(i < start.length()) {
            if(start[i] == 'X') {
                i++;
                continue;
            }

            if(start[i] == 'R') {
                while(j < i) {
                    if(end[j] != 'X')
                        return false;
                    j++;
                }
                while(j < end.length()) {
                    if(end[j] == 'X')
                        j++;
                    else if(end[j] == 'L')
                        return false;
                    else break;
                }
                if(j == end.length()) return false;
                i++;
                j++;
            }

            else if(start[i] == 'L') {
                while(j <= i) {
                    if(end[j] == 'X')
                        j++;
                    else if(end[j] == 'R')
                        return false;
                    else break;
                }
                if(j > i) return false;
                i++;
                j++;
            }
        }
        while(j < end.length()) {
            if(end[j] != 'X')
                return false;
            j++;
     
        }
        return true;
    }

};
// @lc code=end

