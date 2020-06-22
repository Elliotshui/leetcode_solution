/*
 * @lc app=leetcode id=894 lang=cpp
 *
 * [894] All Possible Full Binary Trees
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
	map<int, vector<TreeNode*> > fbt;
    vector<TreeNode*> allPossibleFBT(int N) {
		if(fbt.count(N)) {
			return fbt[N];
		}
		if(N == 1) {
			fbt[1] = vector<TreeNode*>();
			fbt[1].push_back(new TreeNode(0));
			return fbt[1];
		}
		if(N % 2 == 0) {
			return vector<TreeNode*>();
		}	
		fbt[N] = vector<TreeNode*>();
		for(int i = 1; i < N; i += 2) {
			vector<TreeNode*> left = allPossibleFBT(i);
			vector<TreeNode*> right = allPossibleFBT(N - i - 1);
			for(int l = 0; l < left.size(); ++l) {
				for(int r = 0; r < right.size(); ++r) {
					TreeNode *root = new TreeNode(0);
					root->left = left[l];
					root->right = right[r];
					fbt[N].push_back(root);
				}
			}
		}
		return fbt[N];
    }
};
// @lc code=end

