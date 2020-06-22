/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 哨兵节点的使用
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *guard = new ListNode(0);
        guard->next = head;
        ListNode *p = guard;
        while(p->next) {
            if(p->next && p->next->next && p->next->val == p->next->next->val) {
                int v = p->next->val;
                while(p->next && p->next->val == v) {
                    p->next = p->next->next;
                }
            }
            else {
                p = p->next;
            }    
        }
        return guard->next;
        
    }
};
// @lc code=end

