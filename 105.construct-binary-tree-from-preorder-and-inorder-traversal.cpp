/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree_p(vector<int>& preorder, vector<int>& inorder, int lp, int rp, int li, int ri)  {
        if(lp == rp) {
            return NULL;
        }
        int m = li;
        while(inorder[m] != preorder[lp])
            m++;
        struct TreeNode *n = new struct TreeNode(preorder[lp]);
        n->left = buildTree_p(preorder, inorder, lp + 1, lp + 1 + m - li, li, m);
        n->right = buildTree_p(preorder, inorder, lp + 1 + m - li, rp,  m + 1, ri);
        return n;
    }    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree_p(preorder, inorder, 0, preorder.size(), 0, preorder.size());
    }    
};
// @lc code=end

