/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 * 
 * 从数组右上角开始搜索. 若target大, 则排除对应行. 若target小, 则排除对应列. O(max(m, n))的复杂度.
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int c = matrix.size();
        if(c == 0)
            return false;
        int r = matrix[0].size();
        if(r == 0)
            return false;
        
        int pi = 0, pj = r - 1;
        while(pi < c && pj >= 0) {
            if(matrix[pi][pj] == target)
                return true;
            else if(matrix[pi][pj] > target)
                pj--;
            else
                pi++;
        }
        return false;
    }
};

