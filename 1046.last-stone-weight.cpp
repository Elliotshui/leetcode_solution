/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
		priority_queue<int> q;
		for(int i = 0; i < stones.size(); ++i) {
			q.push(stones[i]);
		}
		while(q.size() > 1) {
			int x = q.top(); q.pop();
			int y = q.top(); q.pop();
			if(x == y) continue;
			q.push(max(x, y) - min(x, y));
		}
		return q.empty()? 0 : q.top();
    }
};
// @lc code=end

