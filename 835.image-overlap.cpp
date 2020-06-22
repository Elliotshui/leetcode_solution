/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 */

// @lc code=start
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int res = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, max(count(A, B, i, j), count(B, A, i, j)));
            }
        }
        return res;
    }
    int count(vector<vector<int>>& A, vector<vector<int>>& B, int rowOffset, int colOffset) {
        int sum = 0, n = A.size();
        for (int i = rowOffset; i < n; ++i) {
            for (int j = colOffset; j < n; ++j) {
                sum += A[i][j] * B[i - rowOffset][j - colOffset];
            }
        }
        return sum;
    }
};
// @lc code=end

