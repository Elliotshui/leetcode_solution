/*
 * @lc app=leetcode id=798 lang=cpp
 *
 * [798] Smallest Rotation with Highest Score
 */

// @lc code=start
class Solution {
public:
    int bestRotation(vector<int>& A) {
        int l = A.size();
        vector<int> cnt(l, 0);
        int point = 0;
        for(int i = 0; i < l; ++i)  cnt[i] = 0;
        for(int i = 0; i < l; ++i) {
            if(A[i] == l || A[i] == 0)
                continue;
            else if(A[i] - i <= 0) {
                cnt[i - A[i]]++;
                point++;
            }
            else if(A[i] - i > 0) {
                cnt[l - (A[i] - i)]++;
            }
        }
        int max_point = point, maxk = 0;
        for(int k = 1; k < l; ++k) {
            point = point - cnt[k - 1];
            point += A[k - 1] > 0 && A[k - 1] < l ? 1: 0;   
            if(point > max_point) {
                max_point = point;
                maxk = k;
            }
        }
        return maxk;
    }
};
// @lc code=end

