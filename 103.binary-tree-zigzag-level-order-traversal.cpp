/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		stack<TreeNode*> s1, s2;		
		vector<vector<int>> res;
		s1.push(root);
		while(!s1.empty() || !s2.empty()) {
			vector<int> v;
			if(s2.empty()) {
				while(!s1.empty()) {
					TreeNode *p = s1.top();
					if(p != nullptr) {
						v.push_back(p->val);
						s2.push(p->left);	
						s2.push(p->right);
					}
					s1.pop();
				}
			} else {
				while(!s2.empty()) {
					TreeNode *p = s2.top();
					if(p != nullptr) {
						v.push_back(p->val);
						s1.push(p->right);
						s1.push(p->left);
					}
					s2.pop();
				}
			}
			if(!v.empty()) res.push_back(v);
		}
		return res;
    }
};
// @lc code=end

