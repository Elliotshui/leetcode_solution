/*
 * @lc app=leetcode id=565 lang=cpp
 *
 * [565] Array Nesting
 */

// @lc code=start
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int len = nums.size();
        int maxstep = 0;
        for(int i = 0; i < len; ++i) {
            if(nums[i] == -1)  continue;
            int step = 1, s = nums[i];
            while(s != i) {
                step++;
                int tmp = s;
                s = nums[s];
                nums[tmp] = -1;
            }
            nums[i] = -1;
            if(step > maxstep)
                maxstep = step;
        }
        return maxstep;
    }
};
// @lc code=end

