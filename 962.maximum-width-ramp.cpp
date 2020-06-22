/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 */

// @lc code=start
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int n = A.size();
        vector<int> minl(n, 50001), maxr(n, -1);

        int ans = 0;

        minl[0] = A[0];
        for (int i = 1; i < n; i++)
            minl[i] = min(minl[i - 1], A[i]);

        maxr[n - 1] = A[n - 1];
        for (int i = n - 2; i >= 0; i--)
            maxr[i] = max(maxr[i + 1], A[i]);


        int i = 0, j = 0;
        while (j < n) {
            if (minl[i] <= maxr[j]) {
                ans = max(ans, j - i);
                j++;
            }
            else
                i++;
        }

        return ans;

    }
};
// @lc code=end

