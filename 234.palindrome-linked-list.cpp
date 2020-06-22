/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 */

// @lc code=start
// 1. 快慢指针找中点
// 2. 反转后半部分
// 3. 和前半部分比较
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head1 = slow->next;
        slow->next = NULL;
        head1 = reverse(head1);
        while(head1) {
            if(head->val != head1->val) return false;
            head = head->next;
            head1 = head1->next;
        }
        return true;
    }
    ListNode *reverse(ListNode *head) {
        ListNode *g = new ListNode(0);
        while(head) {
            ListNode *tmp = head->next;
            head->next = g->next;
            g->next = head;
            head = tmp;
        }
        return g->next;
    }
};
// @lc code=end

