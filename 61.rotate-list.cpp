/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        int sz = 0;
        ListNode **tail = &head;
        while(*tail) {
            sz++;
            tail = &((*tail)->next);
        }
        if(sz == 0) return head;
        k = k % sz;
        if(k == 0) return head;
        ListNode *m = head;
        for(int i = 0; i < sz - k - 1; ++i) {
            m = m->next;
        }
        (*tail) = head;
        head = m->next;
        m->next = NULL;
        return head;
    }
};
// @lc code=end

