/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// 快慢指针找到slow后, p从head开始和slow同步遍历, 相遇时即为环起点
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(slow && fast) {
            slow = slow->next;
            fast = fast->next;
            if(!fast) return NULL;
            fast = fast->next;
            if(slow == fast)   
                break;
        }
        if(!fast) return NULL;

        ListNode *p = head;
        while(p != slow) {
            p = p->next;
            slow = slow->next;
        }
        return p;
    }
};
// @lc code=end

