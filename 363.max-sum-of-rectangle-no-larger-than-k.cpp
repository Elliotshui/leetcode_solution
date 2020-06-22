/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 */

// @lc code=start
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		int res = INT_MIN;
		int c = matrix.size(), r = matrix[0].size();
		for(int i = 0; i < r; ++i) {
			vector<int> sum(c, 0);
			for(int j = i; j < r; ++j) {
				for(int k = 0; k < c; ++k){
					sum[k] += matrix[k][j];
				}
				set<int> s{{0}};
				int cursum = 0;
				for(auto n : sum) {
					cursum += n;
					auto p = s.lower_bound(cursum - k);
					if(p != s.end() && cursum - (*p) > res) res = cursum - (*p);		
					s.insert(cursum);
				}
			}
		}
		return res;
    }
};
// @lc code=end

