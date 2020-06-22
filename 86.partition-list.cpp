/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *guardmin = new ListNode(0), *guardmax = new ListNode(0);
        ListNode *p1 = guardmin, *p2 = guardmax;
        while(head) {
            if(head->val < x)  {
                p1->next = head;
                p1 = p1->next;
                head = head->next;
                p1->next = NULL;
            }
            else {
                p2->next = head;
                p2 = p2->next;
                head = head->next;
                p2->next = NULL;
            }
            p1->next = guardmax->next;
        }
        return guardmin->next;
    }
};
// @lc code=end

