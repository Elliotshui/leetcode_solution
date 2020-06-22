/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *guard = new ListNode(0);
        guard->next = head;
        ListNode *p = guard;
        while(p->next) {
            while(p->next && p->next->next && p->next->val == p->next->next->val) {
                p->next = p->next->next;
            }
            p = p->next;
        }
        return guard->next;
    }
};
// @lc code=end

