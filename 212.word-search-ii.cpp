/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class Solution {
public:
	struct TrieNode {
		TrieNode *child[26];
		bool isWord;
		bool visited;
		TrieNode(): isWord(false), visited(false) {
			for(auto& a: child) a = NULL;
		}
	};
	TrieNode *root;
	vector<string> res;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		root = new TrieNode();
		for(auto& word: words) addWord(word);
		for(int i = 0; i < board.size(); ++i) {
			for(int j = 0; j < board[0].size(); ++j) {
				dfs(board, root, "", i, j);
			}
		}	
		return res;
    }
	void addWord(string& word) {
		TrieNode *p = root;
		for(auto& a: word) {
			int c = a - 'a';
			if(p->child[c] == NULL) p->child[c] = new TrieNode();
			p = p->child[c];
		}
		p->isWord = true;
	}
	void dfs(vector<vector<char>>& board, TrieNode *root, string tmp, int i, int j) {
		if(root->isWord && !root->visited) {
			res.push_back(tmp);
			root->visited = true;
		}
		if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '.') return;
		char c = board[i][j];
		int t = c - 'a';
		if(root->child[t]) {
			board[i][j] = '.';
			dfs(board, root->child[t], tmp + c, i, j + 1);
			dfs(board, root->child[t], tmp + c, i + 1, j);
			dfs(board, root->child[t], tmp + c, i, j - 1);
			dfs(board, root->child[t], tmp + c, i - 1, j);
			board[i][j] = c;
		}
	}
};
// @lc code=end

