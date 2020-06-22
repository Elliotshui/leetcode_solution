/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Sequence
 */
// 动态规划, dp[i][j]表示i之前差为j的最大长度(可能有负数所以用map记录) 时间复杂度O(n^2)
// @lc code=start
class Solution {
public:

    int longestArithSeqLength(vector<int>& A) {
        vector<unordered_map<int,int>> dp(A.size());
        int n=A.size();
        int res=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int d=A[i]-A[j];
                if(dp[j].find(d)==dp[j].end()){
                    dp[i][d]=2;
                }
                else{
                    dp[i][d]=dp[j][d]+1;
                }
                res=max(res,dp[i][d]);
            }
        }
        return res;
    }
};
// @lc code=end

