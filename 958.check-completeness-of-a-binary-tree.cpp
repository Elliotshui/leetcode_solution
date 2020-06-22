/*
 * @lc app=leetcode id=958 lang=cpp
 *
 * [958] Check Completeness of a Binary Tree
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
//二叉树的层次遍历
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
               queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (!node) break;
            q.push(node->left);
            q.push(node->right);
        }
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node)
                return false;
        }
        return true;
    }   
};
// @lc code=end

