/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        int paths[m];
        for(int j = 0; j < m; ++j) {
            paths[j] = 1;
        }
        for(int i = 1; i < n; ++i) {
            int tmp = 0;
            for(int j = 0; j < m; ++j) {
                tmp = tmp + paths[j];
                paths[j] = tmp;
            }
        }
        return paths[m - 1];
    }
};

