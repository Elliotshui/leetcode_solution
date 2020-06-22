/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
// 方法一: 最大堆
// 方法二: 求第k大的二分搜索法. 以最大最小值为界进行二分搜索, 统计个数
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
	int left = matrix[0][0], right = matrix.back().back();
        while (left < right) {
            int mid = left + (right - left) / 2;
            int cnt = search_less_equal(matrix, mid);
            if (cnt < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    int search_less_equal(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), i = n - 1, j = 0, res = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= target) {
                res += i + 1;
                ++j;
            } else {
                --i;
            }
        }
        return res;
    }	
    
};
// @lc code=end

