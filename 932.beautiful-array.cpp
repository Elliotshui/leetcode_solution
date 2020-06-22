/*
 * @lc app=leetcode id=932 lang=cpp
 *
 * [932] Beautiful Array
 */

// @lc code=start
//左边全奇数, 右边全偶数, 左右缩减上限递归
class Solution {
public:
    vector<int> beautifulArray(int N) {
        if(N == 1) return vector<int>(1, 1);
        vector<int> res1 = beautifulArray(N / 2);
        vector<int> res2 = beautifulArray((N + 1) / 2);
        vector<int> res;
        for(int n: res1) {
            res.push_back(n * 2);
        }
        for(int m: res2) {
            res.push_back(m * 2 - 1);
        }
        return res;
    }
};
// @lc code=end

