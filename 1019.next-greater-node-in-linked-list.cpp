/*
 * @lc app=leetcode id=1019 lang=cpp
 *
 * [1019] Next Greater Node In Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 
 * 单调栈的思路：
   从右往左遍历数组
   如果栈为空 ：就赋值为0，并把当前元素压栈
   如果栈不为空：就依次出栈，找到大于当前元素的值，直到栈为空
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vals;
        while(head != NULL) {
            vals.push_back(head->val);
            head = head->next;
        }
        vector<int> larger_j;
        for(int i = 0; i < vals.size(); ++i) larger_j.push_back(i + 1);
        for(int i = vals.size() - 1; i >= 0; --i) {
            while(larger_j[i] != vals.size() && vals[i] >= vals[larger_j[i]]) {
                larger_j[i] = larger_j[larger_j[i]];
            }
        }
        for(int i = 0; i < vals.size(); ++i) {
            larger_j[i] = larger_j[i] == vals.size()? 0 : vals[larger_j[i]];
        }
        return larger_j;
    }
};
// @lc code=end

