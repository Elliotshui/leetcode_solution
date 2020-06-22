/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while(l < r) {
            int sum = numbers[l] + numbers[r];
            if(sum < target) ++l;
            else if(sum > target) --r;
            else return vector<int>({l + 1, r + 1});
        }
        return vector<int>({l + 1, r + 1});
    }
};
// @lc code=end

