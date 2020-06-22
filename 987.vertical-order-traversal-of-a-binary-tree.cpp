/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct Node {
        TreeNode *t;
        int depth;
        Node(TreeNode *_t, int _d) {
            t = _t;
            depth = _d;
        }
        bool operator < (const Node& n) const {
            return depth < n.depth || (depth == n.depth && t->val < n.t->val);
        }
    };
    void vertical(TreeNode* root, int x, int y, map<int, set<Node>>& m ) {
        if(!m.count(x)) {
            set<Node> s;
            m[x] = s;
        }
        m[x].insert(Node(root, y));
        if(root->left) vertical(root->left, x - 1, y + 1, m);
        if(root->right) vertical(root->right, x + 1, y + 1, m);
        return;

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, set<Node>> m;
        vertical(root, 0, 0, m);
        vector<vector<int>> res;
        for(auto it = m.begin(); it != m.end(); it++) {
            vector<int> tmp;
            for(auto jt = it->second.begin(); jt != it->second.end(); jt++)
                tmp.push_back((*jt).t->val);
            res.push_back(tmp);
        } 
        return res;
    }
};
// @lc code=end

