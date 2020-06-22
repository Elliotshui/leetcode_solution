/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
	int res;
    int kthSmallest(TreeNode* root, int k) {
		traverse(root, 0, k);
		return res;
    }
	int traverse(TreeNode *root, int n, int k) {
		if(root == NULL) return 0;
		int lcnt = traverse(root->left, n, k);
		if(n + lcnt == k - 1) res = root->val; 
		int rcnt = traverse(root->right, n + lcnt + 1, k);
		return lcnt + rcnt + 1;
	}
};
// @lc code=end

