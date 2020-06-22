/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
		vector<int> res;	
		if(root == nullptr) return res;
		int depth = 0;
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()) {
			if(depth == res.size()) res.push_back(q.front()->val);
			int sz = q.size();
			for(int i = 0; i < sz; ++i) {
				if(q.front()->right) q.push(q.front()->right);
				if(q.front()->left) q.push(q.front()->left);
				q.pop();
			}
			depth++;
		}
		return res;
    }
};
// @lc code=end

