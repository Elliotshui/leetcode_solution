/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> mq(nums.size(), -1);
        int s = 0, e = 0;
        for(int i = 0; i < k; ++i) {
            while(e > s && nums[mq[e - 1]] <= nums[i]) e--;
            mq[e] = i;    
            e++;
        }
        vector<int> res;
        for(int i = 0; i + k <= nums.size(); ++i) {
            while(mq[s] < i) s++;
            res.push_back(nums[mq[s]]);
            if(i + k == nums.size())
                return res;
            while(e > s && nums[mq[e - 1]] <= nums[i + k]) e--;
            mq[e] = i + k;
            e++;
        }
        return res;
    }
};
// @lc code=end

