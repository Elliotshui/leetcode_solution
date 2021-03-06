/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start

/*
状态机算法, 4个数表示之前的状态和之后的状态
0: 之前死, 之后死
1: 之前活, 之后死
2: 之前死, 之后活
3: 之前活, 之后活
state % 2: 之前状态
state / 2: 之后状态
*/
class Solution {
public:

    void gameOfLife(vector<vector<int> >& board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        vector<int> dx{-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> dy{-1, 0, 1, 1, 1, 0, -1, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == 2)) {
                        ++cnt;
                    }
                }
                if (board[i][j] && (cnt < 2 || cnt > 3)) board[i][j] = 2;
                else if (!board[i][j] && cnt == 3) board[i][j] = 3;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] %= 2;
            }
        }
    }

};
// @lc code=end

