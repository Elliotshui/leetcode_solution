/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 0)
            return res;
        
        vector<int> tmp;
        for(int i = 0; i < numRows; ++i) {
            vector<int> tmp1;
            for(int j = 0; j < tmp.size(); ++j) {
                if(j == 0)
                    tmp1.push_back(1);
                else {
                    tmp1.push_back(tmp[j - 1] + tmp[j]);
                }
            }
            tmp1.push_back(1);
            tmp = tmp1;
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end

