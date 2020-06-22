/*
 * @lc app=leetcode id=879 lang=cpp
 *
 * [879] Profitable Schemes
 */

// @lc code=start
class Solution {
public:
int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
    int I = group.size();
    int mod = pow(10, 9) + 7;
    vector<vector<int>> K(G + 1, vector<int>(P + 1, 0));
    for(int g = 0; g <= G; ++g) {
        K[g][0] = 1;
    }
    for(int i = 0; i < I; ++i) {
        vector<vector<int>> tmp(G + 1, vector<int>(P + 1, 1));
        for(int g = 0; g <= G; ++g) {
            for(int p = 0; p <= P; ++p) {
                if((g - group[i] >= 0) && (p - profit[i] >= 0))
                    tmp[g][p] = (K[g][p] + K[g - group[i]][p - profit[i]]) % mod;
                else if(g - group[i] >= 0)
                    tmp[g][p] = (K[g][p] + K[g - group[i]][0]) % mod;
                else
                    tmp[g][p] = K[g][p] % mod;
            }
        }
        for(int g = 0; g <= G; ++g) {
            for(int p = 0; p <= P; ++p) {
                K[g][p] = tmp[g][p];
            }
        }
    }
    return K[G][P];
}
};
// @lc code=end

