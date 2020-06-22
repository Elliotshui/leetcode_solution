/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *guard = new ListNode(0);
        ListNode *tmp;
        while(head) {
            tmp = head->next;
            head->next = NULL;
            insert(guard, head);
            head = tmp;
        }
        return guard->next;
    }
    void insert(ListNode *g, ListNode *p) {
        ListNode **curr = &(g->next);
        while(*curr) {
            if((*curr)->val >= p->val) {
                break;
            }
            else {
                curr = &((*curr)->next);
            }
        }
        p->next = *curr;
        *curr = p;
        return;
    }
};
// @lc code=end

