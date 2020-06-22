/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 */

// @lc code=start
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int res = 0, n = A.size(), M = 1e9 + 7;
        stack<int> st{{-1}};
        vector<int> dp(n + 1);
        for (int i = 0; i < n; ++i) {
            while (st.top() != -1 && A[i] <= A[st.top()]) {
                st.pop();
            }
            dp[i + 1] = (dp[st.top() + 1] + (i - st.top()) * A[i]) % M;
            st.push(i);
            res = (res + dp[i + 1]) % M;
        }
        return res;
    }
};
// @lc code=end

