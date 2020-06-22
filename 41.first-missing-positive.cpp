/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0, sz = nums.size();
        while(i < sz) {
            if(nums[i] > 0 && nums[i] <= sz && nums[nums[i] - 1] != nums[i]) {
                int p = nums[i] - 1, tmp = nums[i];
                nums[i] = nums[p];
                nums[p] = tmp;
            }
            else
            {
                i++;
            }      
        }
        for(int j = 0; j < sz; ++j) {
            if(nums[j] != j + 1)
                return j + 1;
        }
        return sz + 1;
    }
};

