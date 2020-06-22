/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
        if(sz == 0)
            return 0;
        int *left_max = new int[sz];
        int *right_max = new int[sz];
        int max;
        
        max = 0;
        for(int i = 0; i < sz; ++i) {
            left_max[i] = max;
            if(height[i] > max)
                max = height[i];
        }

        max = 0;
        for(int i = sz - 1; i >=0; --i) {
            right_max[i] = max;
            if(height[i] > max) {
                max = height[i];
            }
        }
        int sum = 0;
        for(int i = 0; i < sz; ++i) {
            int min_max = min(left_max[i], right_max[i]);
            if(min_max >= height[i])
                sum += min_max - height[i];
        }
        return sum;
    }
};

