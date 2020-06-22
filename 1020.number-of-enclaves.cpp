/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

// @lc code=start
class Solution {
public:
    struct Node {
        int x, y;
        Node (int x_, int y_) {
            x = x_;
            y = y_;
        }
    };
    int numEnclaves(vector<vector<int>>& A) {
        vector<vector<bool>> v(A.size(), vector<bool>(A[0].size(), false));
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        int res = 0;
        for(int i = 0; i < A.size(); ++i) {
            for(int j = 0; j < A[0].size(); ++j) {
                if(v[i][j] == false && A[i][j] == 1) {
                    queue<Node> q;
                    q.push(Node(i, j));
                    v[i][j] = true;
                    bool can = false;
                    int cnt = 0;
                    while(!q.empty()) {
                        Node n = q.front();
                        if(n.x == 0 || n.x == A.size() - 1 || n.y == 0 || n.y == A[0].size() - 1) {
                            can = true;
                        }
                        cnt++;
                        for(int d = 0; d < 4; ++d) {
                            int x1 = n.x + dx[d], y1 = n.y + dy[d];
                            if(x1 < A.size() && x1 >= 0 && y1 < A[0].size() && y1 >= 0 && v[x1][y1] == false && A[x1][y1] == 1) {
                                q.push(Node(x1, y1));
                                v[x1][y1] = true;
                            }
                        }
                        q.pop();
                    }
                    if(!can) res += cnt;
                }
            }
        }
        return res;
    }
};
// @lc code=end

