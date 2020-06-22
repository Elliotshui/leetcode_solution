/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 * 
 * 转化为找第k小问题
 * 找两个数组中第k/2个较小的数进行比较, 较小者之前都不可能是第k小
 * 若k/2小于某个数组长度, 则另一个数组的前k/2个不可能是第k小
 */

class Solution {
public:
    double findKthSortedArrays(vector<int>& nums1, vector<int>& nums2, int s1, int s2, int k) {
        if(s1 >= nums1.size()) {
            return nums2[s2 + k - 1];
        }
        if(s2 >= nums2.size()) {
            return nums1[s1 + k - 1];
        }
        if(k == 1) {
            return min(nums1[s1], nums2[s2]);
        }

        int n1 = s1 + k/2 - 1 >= nums1.size()? INT_MAX : nums1[s1 + k/2 - 1];
        int n2 = s2 + k/2 - 1 >= nums2.size()? INT_MAX : nums2[s2 + k/2 - 1];
        if(n1 < n2) {
            return findKthSortedArrays(nums1, nums2, s1 + k/2, s2, k - k/2);
        } 
        else {
            return findKthSortedArrays(nums1, nums2, s1, s2 + k/2, k - k/2);
        }

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        if (sum % 2 == 1) {
            return findKthSortedArrays(nums1, nums2, 0, 0, sum / 2 + 1);
        }
        else {
            return (findKthSortedArrays(nums1, nums2, 0, 0, sum / 2) + findKthSortedArrays(nums1, nums2, 0, 0, sum / 2 + 1)) / 2;
        }
    }
};

