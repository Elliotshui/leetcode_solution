/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int cnt = 0;
        ListNode *guard = new ListNode(0);
        guard->next = head;
        ListNode *t = guard;
        for(int i = 0; i < m - 1; ++i) t = t->next;
        ListNode *tail = t->next, *tmp;
        for(int i = m; i < n; ++i) {
            tmp = tail->next;
            tail->next = tmp->next;
            tmp->next = t->next;
            t->next = tmp;
        }
        return guard->next;
    }
};
// @lc code=end

