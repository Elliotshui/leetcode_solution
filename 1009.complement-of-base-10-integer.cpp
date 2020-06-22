/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
class Solution {
public:
    int bitwiseComplement(int N) {
        if(N == 0) return 1;
        int ans = 0;
        int p = 0;
        while(N > 0) {
            ans += (1 - (N % 2)) << p;
            N = N / 2;
            p++;
        }
        return ans;
    }
};
// @lc code=end

