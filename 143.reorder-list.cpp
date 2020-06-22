/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 */

// @lc code=start
// 1. 快慢指针找链表中点
// 2. 翻转后半部分
// 3. 后半部分插入前半部分
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
    void reorderList(ListNode* head) {
        if(head == NULL) return;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *phead = slow->next;
        slow->next = NULL;
        ListNode *rhead = reverse(phead);
        phead = head;
        while(rhead) {
            ListNode *ptmp = phead->next, *rtmp = rhead->next;
            phead->next = rhead;
            rhead->next = ptmp;
            phead = ptmp;
            rhead = rtmp;
        }
         
        return;
    }
    ListNode *reverse(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode *p = head->next;
        head->next = NULL;
        while(p) {
            ListNode *tmp = p->next;
            p->next = head;
            head = p;
            p = tmp;
        }
        return head;
    }
};
// @lc code=end

