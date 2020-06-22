/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string S) {
		vector<int> total(26, 0);
		for(auto c : S) total[c - 'a']++;
		vector<int> cnt(26, 0);
		vector<int> res;
		for(int p = 0; p < S.length(); ++p) {
			char c = S[p];
			cnt[c - 'a']++;
			bool partition = true;
			for(int i = 0; i < 26; ++i) {
				if(cnt[i] > 0 && cnt[i] != total[i]) partition = false;
			}
			if(partition) {
				res.push_back(p);
			}
		}
		for(int i = res.size() - 1; i > 0; --i) {
			res[i] -= res[i - 1];
		}
		res[0]++;
		return res;
    }
};
// @lc code=end

