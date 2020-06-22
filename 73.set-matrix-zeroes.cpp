/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 * 
 * 利用第一行和第一列作为额外空间记录行列是否含有0
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int c = matrix.size();
        if(c == 0)
            return;
        int r = matrix[0].size();
        bool izero = false, jzero = false;
        for(int j = 0; j < r; ++j) {
            if(matrix[0][j] == 0)
                izero = true;
        }
        for(int i = 0; i < c; ++i) {
            if(matrix[i][0] == 0)
                jzero = true;
        }

        for(int i = 1; i < c; ++i) {
            for(int j = 1; j < r; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < c; ++i) {
            for(int j = 1; j < r; ++j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        if(izero) {
            for(int j = 0; j < r; ++j)
                matrix[0][j] = 0;
        }
        if(jzero) {
            for(int i = 0; i < c; ++i)
                matrix[i][0] = 0;
        }
        return;
    }
};

