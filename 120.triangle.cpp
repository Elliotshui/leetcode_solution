/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> minimal;
        minimal.push_back(triangle[0][0]);
        for(int i = 1; i < triangle.size(); ++i) {
            vector<int> tmp;
            tmp.push_back(minimal[0] + triangle[i][0]);
            for(int j = 1; j < i; ++j) {
                tmp.push_back(triangle[i][j] + min(minimal[j - 1], minimal[j]));
            }
            tmp.push_back(minimal[i - 1] + triangle[i][i]);
            for(int k = 0; k < i; ++k) {
                minimal[k] = tmp[k];
            }
            minimal.push_back(tmp[i]);
        }
        int res = minimal[0];
        for(int i = 1; i < minimal.size(); ++i) {
            if(minimal[i] < res)
                res = minimal[i];
        }
        return res;
    }
};
// @lc code=end

