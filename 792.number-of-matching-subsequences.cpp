/*
 * @lc app=leetcode id=792 lang=cpp
 *
 * [792] Number of Matching Subsequences
 */

// @lc code=start
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
		vector<vector<int>> char_pos(26, vector<int>{});
		for(int i = 0; i < S.length(); ++i) {
			char_pos[S[i] - 'a'].push_back(i);
		}
		int res = 0;
		for(auto word: words) {
			int start_pos = -1;
			bool match = true;
			for(auto c: word) {
				start_pos = bsearch(char_pos[c - 'a'], start_pos);
				if(start_pos == char_pos[c - 'a'].size()) {
					match = false;
					break;
				}
				start_pos = char_pos[c - 'a'][start_pos];
			}
			if(match) res++;
		}
		return res;
    }
	int bsearch(vector<int> &v, int pos) {
		int l = 0, r = v.size();
		while(l < r) {
			int m = l + (r - l) / 2;
			if(v[m] > pos) r = m;
			else l = m + 1;
		}
		return l;
	}
};
// @lc code=end

