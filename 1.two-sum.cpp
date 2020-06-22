/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 * 哈希表
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pos; // <value, indice>
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i) {
            int tmp = nums[i];
            if(pos.find(target - tmp) == pos.end()) {
                pos[tmp] = i;
            }
            else {
                int id0 = pos.find(target - tmp) -> second;
                result.push_back(id0);
                result.push_back(i);
                return result;
            }
        }
        return result;
    }
};

