/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<unordered_set<int>> next(numCourses, unordered_set<int>());

		// build map
		for(auto &e: prerequisites) {
			next[e[0]].insert(e[1]);
		}

		queue<int> q;
		vector<int> res;
		for(int i = 0; i < numCourses; ++i) {
			if(next[i].empty()) q.push(i); 
		}
		int cnt = 0;
		while(!q.empty()) {
			int curr = q.front();
			for(int i = 0; i < numCourses; ++i) {
				if(next[i].count(curr)) {
					next[i].erase(curr);
					if(next[i].empty()) q.push(i);
				}
			}
			cnt++;
			res.push_back(curr);
			q.pop();
		}

		if(cnt == numCourses) return res;
		else return vector<int>();
    }
};
// @lc code=end

