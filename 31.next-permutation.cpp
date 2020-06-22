/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();
        if(sz <= 1) return;

        int p = 0;
        for(int i = sz - 1; i > 0; --i) {
            if(nums[i - 1] < nums[i]) {
                p = i;
                break;
            }
        }
        if(p == 0) {
            sort(nums.begin(), nums.end());
        }
        else {
            sort(nums.begin() + p, nums.end());
            for(int j = 0; j + p < sz; ++j) {
                if(nums[p - 1] < nums[p + j]) {
                    int tmp = nums[p + j];
                    nums[p + j] = nums[p - 1];
                    nums[p - 1] = tmp;
                    break;
                }
            }
        }
        return;
    }
};

