/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 */

// @lc code=start
class Solution {
public:
	struct Node {
		string s;
		int lcnt;
		int rcnt;
		Node(string &s_, int lcnt_, int rcnt_) : s(s_), lcnt(lcnt_), rcnt(rcnt_){}
	};
    vector<string> removeInvalidParentheses(string s) {
		int lcnt = 0, rcnt = 0;
		for(auto c : s) {
			if(c == '(') lcnt++;
			if(c == ')') rcnt++;
		}
		unordered_set<string> visited;
		queue<Node*> q;
		q.push(new Node(s, lcnt, rcnt));
		vector<string> res;
		while(!q.empty()) {
			Node *curr = q.front();
			string &s_ = curr->s;
			if(visited.count(s_) || (!res.empty() && s_.length() < res[0].length())) {
				q.pop();
				continue;
			}
			visited.insert(s_);
			if(curr->lcnt == curr->rcnt && check(curr)) res.push_back(curr->s);
			for(int i = 0; i < s_.length(); ++i) {
				if(s_[i] == '(' || s_[i] == ')') {
					string ns = s_.substr(0, i) + s_.substr(i + 1);
					if(visited.count(ns)) continue;
					if(s_[i] == '(') q.push(new Node(ns, curr->lcnt - 1, curr->rcnt));
					else q.push(new Node(ns, curr->lcnt, curr->rcnt - 1));
				}
			}	
			q.pop();
		}
		return res;
    }
	bool check(Node *n) {
		int lcnt = 0;
		string &s_ = n->s;
		for(int i = 0; i < s_.length(); ++i) {
			if(s_[i] == '(') lcnt++;
			else if(s_[i] == ')') {
				if(lcnt > 0) lcnt--;
				else return false;
			} 
		}
		if(lcnt > 0) return false;
		return true;
	}
};
// @lc code=end

