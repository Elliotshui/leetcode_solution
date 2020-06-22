/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 * Tips: 用第84题的方法.
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> q; // a stack of position
        int sz = heights.size();
        heights.push_back(0);
        if(sz == 0)
            return 0;
        int res = 0;
        q.push(0);
        for(int i = 1; i <= sz; ++i) {
            while(!q.empty() && heights[q.top()] > heights[i]) {
                int s = q.top();
                q.pop();
                res = max(res, heights[s] * (i - 1 - (q.empty()? -1:q.top())));
            }
            q.push(i);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int c = matrix.size();
        if(c == 0)
            return 0;
        int r = matrix[0].size();
        if(r == 0)
            return 0;
        
        vector<int> height;
        int res = 0;
        for(int i = 0; i < matrix.size(); ++i) {
            height.resize(matrix[i].size());
            for(int j = 0; j < matrix[0].size(); ++j) {
                if(matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j] += 1;
            }
            res = max(res, largestRectangleArea(height));
        }
        return res;
    }
};
// @lc code=end

