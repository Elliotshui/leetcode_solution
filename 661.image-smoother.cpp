/*
 * @lc app=leetcode id=661 lang=cpp
 *
 * [661] Image Smoother
 */

// @lc code=start
class Solution {
public:

int mean(vector<vector<int>>& M, int i, int j) {
    int cnt = 0, sum = 0;
    int x[3] = {-1, 0, 1}, y[3] = {-1, 0, 1};
    for(int dx = 0; dx < 3; ++dx) {
        for(int dy = 0; dy < 3; ++dy) {
            if(i + x[dx] >= M.size() || i + x[dx] < 0 || j + y[dy] >= M[0].size() || j + y[dy] < 0)
                continue;
            cnt++;
            sum += M[i + x[dx]][j + y[dy]] % 256;
        }
    }
    return sum / cnt;
}
vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    for(int i = 0; i < M.size(); ++i) {
        for(int j = 0; j < M[0].size(); ++j) {
            M[i][j] = (mean(M, i, j) << 8) + M[i][j];
        }
    }
    for(int i = 0; i < M.size(); ++i) {
        for(int j = 0; j < M[0].size(); ++j) {
            M[i][j] = M[i][j] >> 8;
        }
    }
    vector<vector<int>> res = M;
    return res;
}
};
// @lc code=end

