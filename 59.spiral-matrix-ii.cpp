/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int depth = 0;
        vector<vector<int>> result;
        for(int i = 0; i < n; ++i) {
            vector<int> tmp;
            for(int j = 0; j < n; ++j)
                tmp.push_back(0);
            result.push_back(tmp);
        }
        int num = 1;
        while(depth < n - depth) {
            for(int i = depth; i < n - depth; ++i) {
                result[depth][i] = num;
                num++;   
            }
            for(int i = depth + 1; i < n - depth; ++i) {
                result[i][n - depth - 1] = num;
                num++;
            }
            for(int i = n - depth - 2; i >= depth; --i) {
                result[n - depth - 1][i] = num;
                num++;
            }
            for(int i = n - depth - 2; i > depth; --i) {
                result[i][depth] = num;
                num++;
            }
            depth++;
        }
        return result;
    }
};

