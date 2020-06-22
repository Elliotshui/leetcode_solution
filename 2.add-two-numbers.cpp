/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *c1 = l1, *c2 = l2;
        int d = 0;
        ListNode *head = new ListNode(0);
        ListNode *curr = head;
        while(c1 || c2) {
            int d1 = c1 ? c1->val : 0;
            int d2 = c2 ? c2->val : 0;
            curr->next = new ListNode((d + d1 + d2) % 10);
            curr = curr->next;
            d = (d + d1 + d2) / 10;
            if(c1) c1 = c1->next;
            if(c2) c2 = c2->next;
        } 
        if(d != 0) curr->next = new ListNode(d);
        return head->next;
    }
};
// @lc code=end

