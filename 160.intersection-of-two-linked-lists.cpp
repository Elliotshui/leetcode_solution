/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
// 把B链接到A的尾部, 链表找环起点, 记得最后把B从A尾部断开
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL) return NULL;
        ListNode **p = &headA;
        while(*p) {
            p = &((*p)->next);
        } 
        (*p) = headB;
        ListNode *slow = headA, *fast = headA;
        while(fast) {
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
            if(slow == fast) break;
        }
        if(!fast) {
            *p = NULL;
            return NULL;
        }   
        ListNode *h = headA;
        while(h != slow) {
            h = h->next;
            slow = slow->next;
        }
        *p = NULL;
        return slow;
    }
};
// @lc code=end

