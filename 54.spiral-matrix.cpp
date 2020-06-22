/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size(); 
        if(m == 0) {
            return result;
        }
        int n = matrix[0].size();
        if(n == 0) {
            return result;
        }
        int d = 0;
        while(d < n - d && d < m - d) {
            if(d == n - d - 1) {
                for(int i = d; i < m - d; ++i) {
                    result.push_back(matrix[i][d]);
                }
            }
            else if(d == m - d - 1) {
                for(int j = d; j < n - d; ++j){
                    result.push_back(matrix[d][j]);
                }                
            }
            else {
                for(int j = d; j < n - d - 1; ++j) {
                    result.push_back(matrix[d][j]);
                }
                for(int i = d; i < m - d - 1; ++i) {
                    result.push_back(matrix[i][n - d - 1]);
                }
                for(int j = n - d - 1; j > d; --j) {
                    result.push_back(matrix[m - d - 1][j]);
                }
                for(int i = m - d - 1; i > d; --i) {
                    result.push_back(matrix[i][d]);
                }
            }
            d++;
        }
        return result;
    }
};

