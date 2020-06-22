/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 * 小顶堆排序
 * 采用二级指针遍历链表, 非常简洁好用
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
    struct cmp {
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        ListNode *head = NULL, **cur = &head;

        for(auto list:lists) {
            if(list) q.push(list);
        }
        while(!q.empty()) {
            ListNode *t = q.top(); q.pop();
            
            *cur = t;
            cur = &((*cur)->next);

            if(t->next) q.push(t->next);
        }
        return head;
    }
};
// @lc code=end

