/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        if(rowIndex == 0) {
            result.push_back(1);
            return result;
        }
        vector<int> prev = getRow(rowIndex - 1);
        result.push_back(1);
        for(int i = 0; i < prev.size() - 1; ++i) {
            result.push_back(prev[i] + prev[i + 1]);
        }
        result.push_back(1);
        return result;
    }
};
// @lc code=end

