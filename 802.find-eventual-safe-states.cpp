/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
// DFS的思路, 记录三种状态, 0表示未访问, 1表示安全, 2表示不安全.
class Solution {
 public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        if (graph.size() == 0) {
            return res;
        }
        int size = graph.size();
        vector<int> color(size, 0);         // 0: not visited; 1: safe; 2: unsafe.
        for (int i = 0; i < size; ++i) {
            if (dfs(graph, i, color)) {     // the i-th node is safe
                res.push_back(i);
            }
        }
        return res;
    }
private:
    bool dfs(vector<vector<int>> &graph, int start, vector<int> &color) {
        if (color[start] != 0) {
            return color[start] == 1;
        }
        color[start] = 2;       // mark it as unsafe because it is on the path
        for (int next : graph[start]) {
            if (!dfs(graph, next, color)) {
                return false;
            }
        }
        color[start] = 1;       // mark it as safe because no loop is found
        return true;
    }
};
// @lc code=end

