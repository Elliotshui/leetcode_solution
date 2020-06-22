/*
 * @lc app=leetcode id=689 lang=cpp
 *
 * [689] Maximum Sum of 3 Non-Overlapping Subarrays
 */

// @lc code=start
class Solution {
public:
int calsum(vector<int> &vec, vector<int>& nums) {
    int res = 0;
    for(int i = 0; i < vec.size(); ++i) {
        res += nums[vec[i]];
    }
    return res;
}
vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    vector<int> sums;
    sums.push_back(0);
    int sum = 0;
    for(int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        sums.push_back(sum);
    }
    vector<int> sum_sub;
    for(int i = 0; i <= nums.size() - k; ++i) {
        sum_sub.push_back(sums[i + k] - sums[i]);
    }
    vector<vector<int>> max_sub[3];
    for(int i = 0; i < sum_sub.size(); ++i) {
        max_sub[0].push_back({});
        max_sub[1].push_back({});
        max_sub[2].push_back({});
    }
    
    for(int j = 0; j < 3; ++j) {
        for(int i = 0; i < sum_sub.size(); ++i) {
            if(j == 0) {
                if(i == 0)
                    max_sub[j][i].push_back(i);
                else max_sub[j][i].push_back(sum_sub[max_sub[j][i - 1][0]] < sum_sub[i]? i: max_sub[j][i - 1][0]);
                continue;
            }
            if(i - k < 0 || max_sub[j - 1][i - k].empty())
                continue;
            // max[j][i] = max(max[j - 1][i - 1] + sum_sub[i], max[j][i - 1])
            int sum1 = calsum(max_sub[j - 1][i - k], sum_sub) + sum_sub[i];
            int sum2 = max_sub[j][i - 1].empty()? -__INT_MAX__ : calsum(max_sub[j][i - 1], sum_sub);
            
            if(sum1 <= sum2) {
                max_sub[j][i] = max_sub[j][i - 1];
            }
            else {
                max_sub[j][i] = max_sub[j - 1][i - k];
                max_sub[j][i].push_back(i);
            }
        }
    }
    return max_sub[2][sum_sub.size() - 1];
}
};
// @lc code=end

