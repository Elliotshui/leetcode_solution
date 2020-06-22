/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
// 摩尔投票法
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num0 = 0, num1 = 0, cnt0 = 0, cnt1 = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(num0 == nums[i]) cnt0++;
            else if(num1 == nums[i]) cnt1++;
            else if(cnt0 == 0) {
                num0 = nums[i];
                cnt0++;
            }
            else if(cnt1 == 0) {
                num1 = nums[i];
                cnt1++;
            }
            else {
                cnt0--;
                cnt1--;
            }
        }   
        vector<int> res; 
        cnt0 = 0;
        cnt1 = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == num0) cnt0++;
            else if(nums[i] == num1) cnt1++;
        }
        int n = nums.size();
        if (cnt0 > n / 3) res.push_back(num0);
        if (cnt1 > n / 3) res.push_back(num1);
        return res;
    }
};
// @lc code=end

