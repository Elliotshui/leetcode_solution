/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 */

// @lc code=start
// sumj - sumi 在一定范围内. 对每个j, 在之前的sumi中找upper bound和lower bound
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
	    int res = 0;
        long long sum = 0;
        multiset<long long> sums;
        sums.insert(0);
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            res += distance(sums.lower_bound(sum - upper), sums.upper_bound(sum - lower));
            sums.insert(sum);
        }
        return res;	
    }
};
// @lc code=end

