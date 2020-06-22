/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		queue<TreeNode*> q1, q2;
		q1.push(root);
		while(!q1.empty() || !q2.empty()) {
			queue<TreeNode*> &s = q1.empty() ? q2 : q1;
			queue<TreeNode*> &d = q1.empty() ? q1 : q2;
			vector<int> v;
			while(!s.empty()) {
				TreeNode *p = s.front();
				if(p == nullptr) {
					s.pop();
					continue;
				}
				v.push_back(p->val);
				if(q1.empty()) {
					q1.push(p->left);
				}
			}
		}
    }
};
// @lc code=end

