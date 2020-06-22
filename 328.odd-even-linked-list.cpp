/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
       ListNode *godd = new ListNode(0);
       ListNode *geven = new ListNode(0);
       int cnt = 0;
       ListNode *podd = godd, *peven = geven;
       while(head) {
           cnt++;
           if(cnt % 2 == 1) {
               podd->next = head;
               podd = podd->next;
           }
           else {
               peven->next = head;
               peven = peven->next;
           }
           head = head->next;
       } 
       peven->next = NULL;
       podd->next = geven->next;
       return godd->next;
    }
};
// @lc code=end

