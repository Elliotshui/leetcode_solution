/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int sz = 0;
        ListNode *curr = head;
        while(curr != NULL) {
            sz++;
            curr = curr->next;
        } 
        int rcnt = sz / k;
        head = reverseK(head, rcnt, k);
        return head;
    }
    ListNode *reverseK(ListNode *head, int rcnt, int k) {
        if(rcnt == 0)
            return head;
        ListNode *tail = head, *t = head->next;
        for(int i = 0; i < k - 1; ++i) {
            ListNode *tmp = t->next;
            t->next = head;
            head = t;
            t = tmp;
        }
        tail->next = reverseK(t, rcnt - 1, k);
        return head;
    }

};
// @lc code=end

