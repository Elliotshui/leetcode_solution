/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] K-th Symbol in Grammar
 */

// @lc code=start
class Solution {
public:
    int kthGrammar(int N, int K) {
        if(N == 1)
            return 0;
        int prev = kthGrammar(N - 1, (K - 1) / 2 + 1);
        if(prev == 0) return (K - 1) % 2; 
        else return 1 - (K - 1) % 2;
    }
};
// @lc code=end

