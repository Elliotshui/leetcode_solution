/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
    vector<int> largestValues(TreeNode* root) {
		vector<int> res;
		if(root == NULL) return res;
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()) {
			int rowmax = q.front()->val;
			int sz = q.size();
			for(int i = 0; i < sz; ++i) {
				TreeNode* f = q.front();
				q.pop();
				if(f->val > rowmax) rowmax = f->val;
				if(f->left) q.push(f->left);
				if(f->right) q.push(f->right);
			}
			res.push_back(rowmax);
		}
		return res;
    }
};
// @lc code=end

