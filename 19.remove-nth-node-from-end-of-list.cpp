/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * one pass的解法: 记录当前遍历的节点的第前n个节点
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *guard = new ListNode(0);
        guard->next = head;
        int cnt = 0;
        ListNode *toremove = guard;
        while(head != NULL) {
            cnt += 1;
            if(cnt > n)  {
                toremove = toremove->next;
            }
            head = head->next;
        }
        toremove->next = toremove->next->next;
        return guard->next;
    }
};
// @lc code=end

