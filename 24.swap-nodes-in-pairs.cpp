/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 用cnt记录操作的奇偶, 偶操作时删除第二个元素(如果存在)并插入新链表, 奇操作时删除头节点并插入新链表.
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *guard = new ListNode(0), *curr = guard;
        int cnt = 0;
        while(head) {
            if(cnt % 2 == 0 && head->next) {
                curr->next = head->next;
                head->next = head->next->next; 
            } else {
                curr->next = head;
                head = head->next;
            }
            curr = curr->next;
            cnt++;
        }
        return guard->next;
    }
};
// @lc code=end

