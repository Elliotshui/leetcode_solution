/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
public:

    vector<vector<int>> combinationSum(int k, int n, int s) {
        vector<vector<int>> res;
        if(k == 1) {
            if(n >= s && n <= 9) {
                res.push_back({n});
            }
        }
        else {
            for(int i = s; i <= 9; ++i) {
                vector<vector<int>> res1 = combinationSum(k - 1, n - i, i + 1);
                for(int j = 0; j < res1.size(); ++j) {
                    vector<int> tmp;
                    tmp.push_back(i);
                    for(int p = 0; p < res1[j].size(); ++p) {
                        tmp.push_back(res1[j][p]);
                    }
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        return combinationSum(k, n, 1);
    }
};
// @lc code=end

