/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start

//数组范围在1到size之间的: 考虑放置法
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[nums[i] - 1] != nums[i]) {
                int tmp = nums[i];
                nums[i] = nums[tmp - 1];
                nums[tmp - 1] = tmp;
                --i;
            }
        }
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != i + 1) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};
// @lc code=end

