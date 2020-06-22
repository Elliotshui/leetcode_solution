/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;

        unordered_map<Node*, int> node2id;
        unordered_map<int, int> id2id;
        Node *p = head;
        int idx = 0;
        while(p) {
            node2id[p] = idx;
            idx++;
            p = p->next;
        }
        node2id[NULL] = idx;
        p = head;
        idx = 0;
        while(p) {
            id2id[idx] = node2id[p->random];
            idx++;
            p = p->next;
        }
        
        vector<Node*> nodes;
        p = head;
        while(p) {
            nodes.push_back(new Node(p->val));
            p = p->next;
        }
        nodes.push_back(NULL);
        for(int i = 0; i < nodes.size() - 1; ++i) {
            nodes[i]->next = nodes[i + 1];
            nodes[i]->random = nodes[id2id[i]];
        }
        return nodes[0];
    }
};
// @lc code=end

