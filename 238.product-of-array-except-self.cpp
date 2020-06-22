/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> left, right, res;
    left.push_back(1);
    for(int i = 1; i < nums.size(); ++i) {
        left.push_back(nums[i - 1] * left.back());
    }
    right.push_back(1);
    for(int i = nums.size() - 2; i >= 0; --i) {
        right.push_back(nums[i + 1] * right.back());
    }
    for(int i = 0; i < nums.size(); ++i) {
        res.push_back(left[i] * right[nums.size() - i - 1]);
    }
    return res;
}
};
// @lc code=end

