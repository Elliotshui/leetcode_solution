/*
 * @lc app=leetcode id=861 lang=cpp
 *
 * [861] Score After Flipping Matrix
 */

// @lc code=start
// 注意 << 运算符优先级
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        for(int i = 0; i < A.size(); ++i) {
            if(A[i][0] == 1)   continue;
            for(int j = 0; j < A[0].size(); ++j) {
                A[i][j] = 1 - A[i][j];
            }
        }
        int res = 0;
        for(int j = 0; j < A[0].size(); ++j) {
            int cnt = 0;
            for(int i = 0; i < A.size(); ++i) {
                cnt += A[i][j];
            }
            cnt = max(cnt, (int)A.size() - cnt);
            res = res * 2 + cnt;
        }
        return res;
    }
};
// @lc code=end

