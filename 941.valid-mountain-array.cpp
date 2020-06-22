/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */

// @lc code=start
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int len = A.size();
        if(A.size() < 3) {
            return false;
        }
        int p = 0, max = A[0];
        for(int i = 1; i < A.size(); ++i) {
            if(A[i] > max) {
                max = A[i];
                p = i;
            }
        }
        if(p == 0 || p == len - 1) return false;
        for(int i = 0; i < p; ++i) {
            if(A[i] >= A[i + 1]) return false;
        }
        for(int i = p; i < A.size() - 1; ++i) { 
            if(A[i] <= A[i + 1]) return false;
        }
        return true;
        
    }
};
// @lc code=end

