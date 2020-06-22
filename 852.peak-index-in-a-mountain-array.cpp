/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 */

// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
       int max = -1, maxi = 0;
       for(int i = 0; i < A.size(); ++i)
       {
           if(A[i] > max) {
               max = A[i];
               maxi = i;
           }
       } 
       return maxi;
    }
};
// @lc code=end

