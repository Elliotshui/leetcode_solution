/*
 * @lc app=leetcode id=717 lang=cpp
 *
 * [717] 1-bit and 2-bit Characters
 */

// @lc code=start
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int x = -1;
        for(int i = 0; i < bits.size(); ++i) {
            if(x == 1) x = -1;
            else x = bits[i];
        }
        return x == 0;
    }
};
// @lc code=end

