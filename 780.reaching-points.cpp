/*
 * @lc app=leetcode id=780 lang=cpp
 *
 * [780] reacPositions
 */

// @lc code=start
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(tx < sx || ty < sy) return false;
        if(sx == tx && sy == ty) return true;
        if(sx == tx && ty > tx && sy < ty && (ty - sy) % tx == 0) return true;
        if(sy == ty && tx >= ty && sx < tx && (tx - sx) % ty == 0) return true;
        if(ty > tx) return reachingPoints(sx, sy, tx, ty % tx);
        else return reachingPoints(sx, sy, tx % ty, ty);
    }
};
// @lc code=end

