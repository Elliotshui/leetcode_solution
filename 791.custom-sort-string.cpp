/*
 * @lc app=leetcode id=791 lang=cpp
 *
 * [791] Custom Sort String
 */

// @lc code=start
class Solution {
public:
	map<char, int> pos;
	static bool less_char(const pair<char, int>& a, const pair<char, int>& b) {
		return a.second < b.second;
	}
    string customSortString(string S, string T) {
		for(int i = 0; i < S.length(); ++i) {
			pos[S[i]] = i;
		}
		vector<pair<char, int>> v;
		for(auto c : T) {
			int p = pos.count(c) ? pos[c] : -1;
			v.push_back(make_pair(c, p));
		}
		sort(v.begin(), v.end(), less_char);
		string res;
		for(auto c : v) res += c.first;
		return res;
    }
};
// @lc code=end

