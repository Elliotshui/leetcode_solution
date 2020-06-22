/*
 * @lc app=leetcode id=726 lang=cpp
 *
 * [726] Number of Atoms
 */

// @lc code=start
class Solution {
public:
    string countOfAtoms(string formula) {
		map<string, int> cnt;
		int s = 0;
		helper(formula, s, cnt);
		stringstream res;
		for(auto &atom : cnt) {
			res << atom.first;
			if(atom.second != 1) {
				res << atom.second;
			}
		}
		return res.str();
    }
	void helper(string &formula, int &s, map<string, int> &upper_cnt) {
		map<string, int> cnt;
		while(s < formula.length()) {
			if(formula[s] == ')') {
				s++;
				int c = get_num(formula, s);
				for(auto &atom : cnt) {
					if(!upper_cnt.count(atom.first)) { 
						upper_cnt[atom.first] = 0;
					}
					upper_cnt[atom.first] += atom.second * c;
				}
				return;
			}
			if(formula[s] >= 'A' && formula[s] <= 'Z') {
				s++;
				string atom = formula[s - 1] + get_lower(formula, s);
				int c = get_num(formula,s);
				if(!cnt.count(atom)) {
					cnt[atom] = 0;
				}
				cnt[atom] += c;
			}
			else if(formula[s] == '(') {
				s++;
				helper(formula, s, cnt);
			}
		}
		upper_cnt = cnt;
	}
	int get_num(string &formula, int &s) {
		int num = 0;
		while(s < formula.length()) {
			if(formula[s] >= '0' && formula[s] <= '9') {
				num = num * 10 + formula[s] - '0';
				s++;
			} else break;
		}
		return num == 0 ? 1 : num;
	}
	string get_lower(string &formula, int &s) {
		string lower = "";
		while(s < formula.length()) {
			if(formula[s] <= 'z' && formula[s] >= 'a') {
				lower += formula[s];
				s++;
			} else break;	
		}
		return lower;
	}
};
// @lc code=end

