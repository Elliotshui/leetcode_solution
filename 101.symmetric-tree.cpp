/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
		if(!root) return true;
		return traverse(root->left, root->right);
    }
	bool traverse(TreeNode *l, TreeNode *r) {
		if(l == nullptr && r == nullptr) return true;
		if(l && r && l->val == r->val) {
			return traverse(l->left, r->right) && traverse(l->right, r->left);
		}
		return false;
	}
};
// @lc code=end

