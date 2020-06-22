/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 */

// @lc code=start
class Solution {
public:
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int product = 1;
    int j = 0, cnt = 0;
    for(int i = 0; i < nums.size(); ++i) {
        while(j < nums.size()) {
            product *= nums[j];
            if(product >= k) {
                product /= nums[j];
                break;
            }
            j++;
        }
        product /= nums[i];
        cnt += j - i;
        if(j == i) {
            j = i + 1;
            product = 1;
        }
    }
    return cnt;
}
};
// @lc code=end

