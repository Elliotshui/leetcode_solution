/*
 * @lc app=leetcode id=1038 lang=cpp
 *
 * [1038] Binary Search Tree to Greater Sum Tree
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
    TreeNode* bstToGst(TreeNode* root) {
		traverse(root, 0);
		return root;
    }
	int traverse(TreeNode *root, int n) {
		if(!root) return 0;
		int l = traverse(root->right, n);
		int r = traverse(root->left, n + l + root->val);
		int res = l + r + root->val;
		root->val += n + l;
		return res;
	}
};
// @lc code=end

