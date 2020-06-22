/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
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
	int sum;
    int sumRootToLeaf(TreeNode* root) {
		sum = 0;
		traverse(root, 0);
		return sum;
    }
	void traverse(TreeNode *root, int n) {
		if(!root) return;
		if(!root->left && !root->right) {
			sum += n * 2 + root->val;
			return;
		}
		traverse(root->left, n * 2 + root->val);
		traverse(root->right, n * 2 + root->val);
	}
};
// @lc code=end

