/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
// BFS 或者 DFS 都可以做
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0, r = grid[0].size();
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] != 1)
                    continue;
                int cnt = 0;
                queue<int> q;
                q.push(i * r + j);
                grid[i][j] = 0;
                while(!q.empty()) {
                    int i1 = q.front() / r;
                    int j1 = q.front() % r;
                    for(int d = 0; d < 4; ++d) {
                        int i2 = i1 + dx[d];
                        int j2 = j1 + dy[d];
                        if(i2 >= 0 && i2 < grid.size() && j2 >= 0 && j2 < r && grid[i2][j2] == 1) {
                            q.push(i2 * r + j2);
                            grid[i2][j2] = 0;
                        }
                    } 
                    cnt++;
                    q.pop();
                }
                if(cnt > res) res = cnt;
            }
        }
        return res;
    }

};
// @lc code=end

