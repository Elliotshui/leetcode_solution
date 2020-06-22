/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
// 数组值域[1, size()], 考虑使用放置法
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
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
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
// @lc code=end

