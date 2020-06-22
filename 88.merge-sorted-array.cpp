/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m + n - 1, p1 = m - 1, p2 = n - 1;
        while(p >= 0) {
            if(p1 < 0 || (p2 >= 0 && nums1[p1] < nums2[p2])) {
                nums1[p] = nums2[p2];
                p2--;
            }
            else {
                nums1[p] = nums1[p1];
                p1--;
            }
            p--;
        }
    }
};
// @lc code=end

