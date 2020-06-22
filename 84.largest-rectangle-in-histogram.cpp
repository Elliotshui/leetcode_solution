/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
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
};
// @lc code=end

