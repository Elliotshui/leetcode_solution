/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
		int res = __INT_MAX__;
		if(root == nullptr) return 0;
		helper(res, root, 1);
		return res;
    }
	void helper(int &mindepth, TreeNode *root, int depth) {
		if(root->left == nullptr && root->right == nullptr) {
			mindepth = min(mindepth, depth);
			return;
		}
		if(root->left) helper(mindepth, root->left, depth + 1);
		if(root->right) helper(mindepth, root->right, depth + 1);
	}
};
// @lc code=end

