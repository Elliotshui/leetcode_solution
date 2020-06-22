/*
 * @lc app=leetcode id=809 lang=cpp
 *
 * [809] Expressive Words
 */

// @lc code=start

class Solution {
public:
	struct group {
		char c;
		int num;
		group(char c_, int n_): c(c_), num(n_) {}
	};
	vector<group> s;
    int expressiveWords(string S, vector<string>& words) {
		group g('\0', 0);
		for(char &c : S) {
			if(c != g.c) {
				s.push_back(g);
				g.c = c;
				g.num = 1;
			} else {
				g.num++;
			}
		}
		s.push_back(g);
		int res = 0;
		for(string &word : words) {
			int i = 0;
			bool match = true;
			group last('\0', 0);
			for(char &c : word) {
				match = check(c, last, i);
				if(!match) break;
			}
			match = check('\0', last, i);
			if(match && i == s.size()) res++;
		}
		return res;
    }
	bool check(char c, group &last, int &i) {
		if(c == last.c) {
			last.num++;
			return true;
		}
		else {
			if(i == s.size()) return false;
			else if(last.c != s[i].c) return false;
			else {
				if((s[i].num <= 2 && last.num == s[i].num) || (s[i].num > 2 && last.num <= s[i].num)) {
					i++;
					last.c = c;
					last.num = 1;
					return true;
				}
				else return false;
			}	
		}
	}

};
// @lc code=end

