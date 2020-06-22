/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
public:
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    map<int, int> m;
    int minlen = __INT_MAX__;
    for(int i = 0; i < nums.size(); ++i) {
        auto p = m.find(nums[i]);
        if(p!= m.end()) {
            if(i - p->second < minlen) minlen = i - p->second;
            p->second = i;
        }
        else {
            m[nums[i]] = i;
        }
    }
    return minlen <= k;
}
};
// @lc code=end

