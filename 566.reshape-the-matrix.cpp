/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int rn = nums.size();
        int cn = nums[0].size();

        if(r * c != rn * cn)
            return nums;
        vector<vector<int>> res;
        vector<int> row;
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                row.push_back(nums[(i * c + j) / cn][(i * c + j) % cn]);
            }
            res.push_back(row);
            row.clear();
        }
        return res;
    }
};
// @lc code=end

