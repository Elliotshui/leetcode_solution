/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
class Solution {
public:

    void findComb(vector<vector<int>>& result, vector<int>& tmp, vector<int>& candidates, int pos, int target) {
        if(target == 0) {
            result.push_back(tmp);
            return;
        }
        else if(target < 0 || pos >= candidates.size()) 
            return;

        tmp.push_back(candidates[pos]);
        findComb(result, tmp, candidates, pos, target - candidates[pos]);
        tmp.pop_back();

        findComb(result, tmp, candidates, pos + 1, target);
        return;
    } 


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        findComb(result, tmp, candidates, 0, target);
        return result;
    }
};

