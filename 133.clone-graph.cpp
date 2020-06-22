/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
		map<Node*, Node*> nodemap;
		if(node == nullptr) return nullptr;
		traverse(nodemap, node);
		return buildgraph(nodemap, node);	
    }
	void traverse(map<Node*, Node*>& nodemap, Node *node) {
		queue<Node*> q;
		q.push(node);
		while(!q.empty()) {
			Node *p = q.front();
			nodemap[p] = new Node(p->val);
			for(auto next : p->neighbors) {
				if(nodemap.count(next) == 0) q.push(next);
			}
			q.pop();
		}
	}
	Node *buildgraph(map<Node*, Node*>& nodemap, Node *node) {
		for(auto nodepair : nodemap) {
			for(auto next: nodepair.first->neighbors) {
				nodepair.second->neighbors.push_back(nodemap[next]);
			}
		}
		return nodemap[node];
	}
};
// @lc code=end

