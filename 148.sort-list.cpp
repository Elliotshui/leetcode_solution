/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head1 = slow->next;
        slow->next = NULL;
        head = sortList(head);
        head1 = sortList(head1);
        return merge(head, head1);
    }
    ListNode* merge(ListNode *p1, ListNode *p2) {
        ListNode *g = new ListNode(0);
        ListNode *p = g;
        while(p1 && p2) {
            ListNode *tmp;
            ListNode* &t = p1->val > p2->val? p2:p1;
            tmp = t->next;
            p->next = t;
            p = t;
            t = tmp;
        }
        if(p1) p->next = p1;
        if(p2) p->next = p2;
        return g->next;
    }

};
// @lc code=end

