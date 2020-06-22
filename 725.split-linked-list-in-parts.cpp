/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode *p = root;
        int sz = 0;
        while(p) {
            sz++;
            p = p->next;
        }
        int cnt = sz / k, mod = sz % k;
        vector<ListNode*> res;
        p = root;
        for(int i = 0; i < mod; ++i) {
            res.push_back(p);
            for(int j = 0; j < cnt; ++j) {
                p = p->next;
            }
            ListNode *tmp = p->next;
            p->next = NULL;
            p = tmp;
        }
        for(int i = 0; i < k - mod; ++i) {
            res.push_back(p);
            for(int j = 0; j < cnt - 1; ++j) {
                p = p->next;
            }
            if(p) {
                ListNode *tmp = p->next;
                p->next = NULL;
                p = tmp;
            }
        }
        return res;
    }
};
// @lc code=end

