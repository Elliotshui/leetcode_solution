/*
 * @lc app=leetcode id=927 lang=cpp
 *
 * [927] Three Equal Parts
 */

// @lc code=start
// 前中后三段1的个数必须相等
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
               int cntOne = 0, n = A.size();
        for (int num : A) {
            if (num == 1) ++cntOne;
        }
        if (cntOne == 0) return {0, n - 1};
        if (cntOne % 3 != 0) return {-1, -1};
        int k = cntOne / 3, start = 0, mid = 0, end = 0, cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 0) continue;
            if (cnt == 0) start = i;
            ++cnt;
            if (cnt == k + 1) mid = i;
            if (cnt == 2 * k + 1) {end = i; break;}
        }
        while (end < n && A[start] == A[mid] && A[mid] == A[end]) {
            ++start; ++mid; ++end;
        }
        if (end == n) return {start - 1, mid};
        return {-1, -1};
    } 
    
};
// @lc code=end

