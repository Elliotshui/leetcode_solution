/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */

// @lc code=start

// 注意边界条件
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 1, cnt = 0;
        while(l < r && r < nums.size()) {
            
            int nl = nums[l], nr = nums[r];
            if(nr - nl == k) {
                cnt++;
                while(r < nums.size() &&  nums[r] == nr) 
                    r++;
                while(r < nums.size() - 1 && nums[r] == nums[r + 1])
                    r++;
            }
            else if(nr - nl > k) {
                while(l < r && nums[l] == nl)
                    l++;
                if(r == l) r++;
            }
            else {
                while(r < nums.size() && nums[r] == nr) {
                    r++;
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

