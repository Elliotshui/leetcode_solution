/*
 * @lc app=leetcode id=1034 lang=cpp
 *
 * [1034] Coloring A Border
 */

// @lc code=start
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

class Solution {
public:
    bool inboundary(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || r >= grid.size())
            return false;
        if (c < 0 || c >=  grid[0].size())
            return false;
        return true;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
		int vis[55][55];
        queue<int> q;
        vector<int> borders;
        memset(vis, 0, sizeof(vis));
        q.push(r0 * 100 + c0);
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            bool isborder = false;
            int c1, r1;
            r1 = tmp / 100;
            c1 = tmp % 100;
            vis[r1][c1] = true;
            for (int i = 0; i < 4; i++) {
                int r =  r1 + dx[i];
                int c =  c1 + dy[i];
                if (inboundary(r, c, grid)) {
                    if (grid[r1][c1] == grid[r][c]) {
                        if (!vis[r][c])   
                            q.push(r*100 + c);
                    }
                    else
                        isborder = true;
                } else
                    isborder = true;
            }
            if (isborder)
                borders.push_back(tmp);
        }
        for (int i = 0; i < borders.size(); i++)
            grid[borders[i] / 100][borders[i] % 100] = color;
        return grid;        
    }
};
// @lc code=end

