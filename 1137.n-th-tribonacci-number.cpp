/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        vector<int> t = {0, 1, 1};
        for(int i = 3; i <= n; ++i) {
            t.push_back(t[i - 1] + t[i - 2] + t[i - 3]);
        }
        return t[n];
    }
};
// @lc code=end

