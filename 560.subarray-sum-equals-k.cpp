/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int sum = 0, res = 0;
        cnt[sum] = 1;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if(cnt.count(sum - k)) {
                res += cnt[sum - k];
            }
            if(!cnt.count(sum)) {
                cnt[sum] = 0;
            }
            cnt[sum]++;
        }
        return res;
    }
};
// @lc code=end

