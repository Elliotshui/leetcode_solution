/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
		vector<int> dotpos;
		vector<string> res;
		dotpos.push_back(0);
		helper(res, s, 0, dotpos, 1);
		return res;
	}
	void helper(vector<string> &res, string s, int fcnt, vector<int> &dotpos, int p) {
		if(fcnt < 4 && p == s.length() + 1) return;
		if(fcnt > 4) return;
		if(fcnt == 4 && p < s.length() + 1) return;
		if(fcnt == 4 && p == s.length() + 1) {
			int i = 1, j = 0;
			string tmp = "";
			for(int j = 0; j < s.length(); ++j) {
				if(j == dotpos[i]) {
					tmp += '.';
					i++;
				}
				tmp += s[j];
			}
			res.push_back(tmp);
			return;
		} 
		int tmp = 0;
		for(int i = dotpos.back(); i < p; ++i) {
			tmp = tmp * 10 + s[i] - '0';
			if(tmp > 255) return;
		}
		if(tmp != 0) helper(res, s, fcnt, dotpos, p + 1);	
		dotpos.push_back(p);
		helper(res, s, fcnt + 1, dotpos, p + 1);
		dotpos.pop_back();
	}

};
// @lc code=end

