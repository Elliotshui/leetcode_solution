/*
 * @lc app=leetcode id=1041 lang=cpp
 *
 * [1041] Robot Bounded In Circle
 */

// @lc code=start
class Solution {
public:
    int dy[4] = {1, 0, -1, 0};
    int dx[4] = {0, 1, 0, -1};
    void act(int &x, int &y, int &d, char ins) {
        if(ins == 'G') {
            x += dx[d];
            y += dy[d];
        }
        else if (ins == 'L') {
            d = (d + 3) % 4;
        }
        else d = (d + 5) % 4;
    }
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, d = 0;
            for(int j = 0; j < instructions.length(); ++j) {
                act(x, y, d, instructions[j]);
            }
        if(x == 0 && y == 0 || d > 0) return true;
        return false;
    }
};
// @lc code=end

