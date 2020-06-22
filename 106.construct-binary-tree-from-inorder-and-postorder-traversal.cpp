/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree_p(vector<int>& inorder, vector<int>& postorder, int li, int ri, int lp, int rp) {
        if(lp == rp)
            return NULL;
        int m = li;
        while(inorder[m] != postorder[rp - 1])
            m++;
        struct TreeNode* n = new struct TreeNode(postorder[rp - 1]);
        n->left = buildTree_p(inorder, postorder, li, m, lp, lp + m - li);
        n->right = buildTree_p(inorder, postorder, m + 1, ri, lp + m - li, rp - 1);
        return n;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree_p(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
};
// @lc code=end

