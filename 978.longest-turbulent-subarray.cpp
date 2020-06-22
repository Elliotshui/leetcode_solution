/*
 * @lc app=leetcode id=978 lang=cpp
 *
 * [978] Longest Turbulent Subarray
 */

// @lc code=start
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if(A.size() == 0) return 0;
        int ans = 1, prev = 1;
        for(int i = 1; i < A.size(); ++i) {
            if(A[i] == A[i - 1]) prev = 1;
            else if(A[i] > A[i - 1] && prev > 1 && A[i - 1] < A[i - 2]) prev++;
            else if(A[i] < A[i - 1] && prev > 1 && A[i - 1] > A[i - 2]) prev++;
            else prev = 2;
            if(prev > ans) ans = prev;
        }
        return ans;
    }
};
// @lc code=end

