/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

3// @lc code=start
class Solution {
public:
    int numTilings(int N) {
        vector<int> res(N + 1, 0);
        int m = pow(10, 9) + 7;
        res[0] = 1;
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= 2; ++j) {
                if(i - j >= 0) 
                    res[i] = (res[i] + res[i - j]) % m;
            }
            for(int j = 3; j <= N; ++j) {
                if(i - j >= 0) 
                    res[i] = ((res[i] + (res[i - j] * 2) % m)) % m;
            }
        }
       return res[N]; 
    }
};
// @lc code=end

3
