/*
 * @lc app=leetcode id=898 lang=cpp
 *
 * [898] Bitwise ORs of Subarrays
 */

// @lc code=start
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> res, cur;
        for (int i : A) {
            unordered_set<int> tmp = {i};
            for (int j : cur) tmp.insert(i | j);
            cur = tmp;
            for (int j : cur) res.insert(j);
        }
        return res.size();
    }
};
// @lc code=end

