/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        int sz = 0;
        ListNode *t = head;
        while(t) {
            sz++;
            t = t->next;
        }
        int m = sz / 2;
        if(sz == 1) return new TreeNode(head->val);
        t = head;
        for(int i = 0; i < m - 1; ++i) {
            t = t->next;
        }
        TreeNode *root = new TreeNode(t->next->val);
        root->right = sortedListToBST(t->next->next);
        t->next = NULL;
        root->left = sortedListToBST(head);
        return root;
    }

};
// @lc code=end

