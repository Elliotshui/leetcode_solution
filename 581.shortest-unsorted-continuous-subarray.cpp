/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// @lc code=start

// 记录存在逆序对的区间
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int i, j;
        for(i = 0; i < nums.size() && nums[i] == tmp[i]; ++i);
        for(j = nums.size() - 1; j >= i && nums[j] == tmp[j]; --j);
        return j - i == 0? 0: j - i + 1;
    }
};
// @lc code=end

