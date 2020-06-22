/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> res(A.size(), 0);
        int front = 0, back = A.size() - 1;
        for(int i = 0; i < A.size(); ++i) {
            if(A[i] % 2 == 0) res[front++] = A[i]; 
            else res[back--] = A[i]; 
        }
        return res; 
    }
};
// @lc code=end

