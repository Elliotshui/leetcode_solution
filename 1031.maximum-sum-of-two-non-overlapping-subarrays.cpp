/*
 * @lc app=leetcode id=1031 lang=cpp
 *
 * [1031] Maximum Sum of Two Non-Overlapping Subarrays
 * 暴力搜索, O(n^2), 注意跳过重叠的部分
 */

// @lc code=start
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> sumL(A.size() + 1, 0), sumM(A.size() + 1, 0), sum(A.size() + 1, 0);
        for(int i = 1; i <= A.size(); ++i) {
            sum[i] = sum[i - 1] + A[i - 1];
            if(i >= L) sumL[i] = sum[i] - sum[i - L];
            if(i >= M) sumM[i] = sum[i] - sum[i - M];
        } 
        int res = 0;
        for(int i = L; i <= A.size(); ++i) {
            for(int j = M; j <= A.size(); ++j) {
                if(i - L >= j || j - M >= i) {
                    res = max(res, sumL[i] + sumM[j]);
                }
            }
        }
        return res;
    }
};
// @lc code=end

