/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
		unordered_set<long> s;
		queue<pair<long, int>> q;
		q.push(make_pair(n, 0));
		s.insert(n);
		while(!q.empty()) {
			long curr = q.front().first;
			for(long i = 1; i * i <= curr; ++i) {
				if(i * i == curr) return q.front().second + 1;
				if(s.count(curr - i * i) == 0) {
					s.insert(curr - i * i);
					q.push(make_pair(curr - i * i, q.front().second + 1));
				}
			}
			q.pop();
		}
		return -1;
    }

};
// @lc code=end

