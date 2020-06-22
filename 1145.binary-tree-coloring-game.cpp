/*
 * @lc app=leetcode id=1145 lang=cpp
 *
 * [1145] Binary Tree Coloring Game
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int count(TreeNode* root, vector<int>& cnt, vector<TreeNode*>& nodes){
		if(root == NULL) return 0;
		cnt[root->val] = count(root->left, cnt, nodes) + count(root->right, cnt, nodes) + 1;
		nodes[root->val] = root;
		return cnt[root->val];
	}
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
		vector<int> cnt(n + 1, 0);
		vector<TreeNode*> nodes(n + 1, NULL);
		count(root, cnt, nodes);
		int lc = nodes[x]->left ? cnt[nodes[x]->left->val] : 0;	
		int lr = nodes[x]->right ? cnt[nodes[x]->right->val] : 0;
		int lp = n - lc - lr - 1;
		if(lp * 2 > n || lr * 2 > n || lc * 2 > n) {
			return true;
		} else {
			return false;
		}
    }
};
// @lc code=end

