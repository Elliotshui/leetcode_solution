/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 */

// @lc code=start
class Solution {
public:

int findShortestSubArray(vector<int>& nums) {
    
    unordered_map<int, int> f;
    for(int num: nums) {
        if(f.count(num) == 0)
            f[num] = 0;
        f[num] += 1;
    }
    unordered_map<int, int> l, r;
    for(int i = 0; i < nums.size(); ++i) {
        if(l.count(nums[i]) == 0)
            l[nums[i]] = i;
    }
    for(int j = nums.size() - 1; j >= 0; --j) {
        if(r.count(nums[j]) == 0)
            r[nums[j]] = j;
    }
    int max_f = 0, min_len = __INT32_MAX__;
    for(int i = 0; i < nums.size(); ++i) {
        if(f[nums[i]] > max_f) {
            max_f = f[nums[i]];
            min_len = r[nums[i]] - l[nums[i]] + 1;
        }
        else if(f[nums[i]] == max_f) {
            min_len = r[nums[i]] - l[nums[i]] + 1 < min_len? r[nums[i]] - l[nums[i]] + 1: min_len;
        }
    }
    return min_len;
}

};
// @lc code=end

