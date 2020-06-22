/*
 * @lc app=leetcode id=864 lang=cpp
 *
 * [864] Shortest Path to Get All Keys
 */

// @lc code=start
class Solution {
public:

struct Node {
    int x, y;
    int state;
    int step;
    Node(int x_, int y_, int state_, int step_) {
        x = x_;
        y = y_;
        state = state_;
        step = step_;
    }
    Node() {}
};
int shortestPathAllKeys(vector<string>& grid) {
    int r = grid.size(), c = grid[0].length();
    int sx, sy, K = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(grid[i][j] == '@'){
                sx = i;
                sy = j;
                
            }
            else if(grid[i][j] <= 'F' && grid[i][j] >= 'A') {
                K++;
            }
        }
    }
    Node s(sx, sy, 0, 0);
    vector<vector<bool>> visited(r * c, vector<bool>(1<<K, false));
    queue<Node> q;
    q.push(s);
    visited[sx * c + sy][0] = true;
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    while(!q.empty()) {
        Node t = q.front();
        if(t.state == (1<<K) - 1)
            return t.step;
        for(int d = 0; d < 4; ++d) {
            int x = t.x + dx[d], y = t.y + dy[d];
            Node t1;
            if(x < 0 || x >= r || y < 0 || y >= c || grid[x][y] == '#')
                continue;
            if(grid[x][y] <= 'F' && grid[x][y] >= 'A') {
                if((t.state & (1<<(grid[x][y] - 'A'))) == 0)
                    continue;
            }
            t1.state = t.state;
            if(grid[x][y] <= 'f' && grid[x][y] >= 'a') {
                if((t.state & (1<<(grid[x][y] - 'a'))) == 0)
                    t1.state = t.state +(1<<(grid[x][y] - 'a'));
                else
                    t1.state = t.state;
            }
            t1.step = t.step + 1;
            t1.x = x;
            t1.y = y;
            if(!visited[x * c + y][t1.state]) {
                q.push(t1);
                visited[x * c + y][t1.state] = true;
            }
        }
        q.pop();
    }
    return -1;
}
};
// @lc code=end

