/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		//build graph
		vector<vector<int>> next(numCourses, vector<int>());
		for(auto &dep : prerequisites) {
			next[dep[1]].push_back(dep[0]);
		}

		//traverse until loop
		for(int i = 0; i < numCourses; ++i) {
			queue<int> node_queue;
			vector<bool> visited(numCourses, false);
			node_queue.push(i);
			while(!node_queue.empty()) {
				int curr = node_queue.front();
				visited[curr] = true;
				for(int j = 0; j < next[curr].size(); ++j) {
					if(next[curr][j] == i) return false;
					if(visited[next[curr][j]]) continue;
					node_queue.push(next[curr][j]);
				}
				node_queue.pop();
			}
		}
		return true;
    }
};
// @lc code=end

