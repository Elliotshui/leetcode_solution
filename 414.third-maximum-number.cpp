/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

// @lc code=start
class Solution {
public:
long findMax(vector<int>& nums, long max) {
    long res = -__LONG_MAX__;
    for(int i = 0; i < nums.size(); ++i) {
        if((long)nums[i] > res && (long)nums[i] < max) {
            res = nums[i];
        }
    }
    return res;
}
int thirdMax(vector<int>& nums) {
    long max = findMax(nums, __LONG_MAX__);
    long secondmax = findMax(nums, max);
    long thirdmax = findMax(nums, secondmax);
    if(thirdmax != -__LONG_MAX__) return thirdmax;
    else return max;
}
};
// @lc code=end

