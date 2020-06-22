/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */
class Solution {
public:
    void swap(vector<vector<int>>& matrix, int i1, int j1, int i2, int j2) {
        int tmp = matrix[i1][j1];
        matrix[i1][j1] = matrix[i2][j2];
        matrix[i2][j2] = tmp;
        return;
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n - 1; ++i) {
            for(int j = i; j < n - i - 1; ++j) {
                swap(matrix, i, j, j, n - i - 1);
                swap(matrix, n - i - 1, n - j - 1, n - j - 1, i);
                swap(matrix, i, j, n - i - 1, n - j - 1);
            }
        }
        return;
    }
};

