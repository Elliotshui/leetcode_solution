/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		int l = 0, r = arr.size();
		while(l < r) {
			int m = l + (r - l) / 2;
			if(arr[m] < x) l = m + 1;
			else r = m;
		}
		int i = l - 1, j = l, cnt = 0;
		vector<int> res;
		while(cnt < k) {
			if(j == arr.size()) {
				res.push_back(arr[i]);
				i--;
			}
			else if(i == -1) {
				res.push_back(arr[j]);
				j++;
			}
			else {
				if(arr[j] - x >= x - arr[i]) {
					res.push_back(arr[i]);
					i--;
				} else {
					res.push_back(arr[j]);
					j++;
				}
			}
			cnt++;
		}
		sort(res.begin(), res.end());
		return res;
    }
};
// @lc code=end

