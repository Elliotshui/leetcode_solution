/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> res1, res2;
		traverse(res1, root1);
		traverse(res2, root2);	
		if(res1.size() != res2.size()) return false;
		for(int i = 0; i < res1.size(); ++i) {
			if(res1[i] != res2[i]) return false;
		}
		return true;
    }
	void traverse(vector<int>& res, TreeNode *root){
		if(root == NULL) return;
		if(root->left == NULL && root->right == NULL) {
			res.push_back(root->val);
			return;
		}	
		traverse(res, root->left);	
		traverse(res, root->right);
		return;
	}
};
// @lc code=end

