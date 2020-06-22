/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
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
        findComb(result, tmp, candidates, pos + 1, target - candidates[pos]);
        tmp.pop_back();

        while(pos < candidates.size() - 1 && candidates[pos] == candidates[pos + 1])
            pos++;
        findComb(result, tmp, candidates, pos + 1, target);
        return;
    } 
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        findComb(result, tmp, candidates, 0, target);
        return result;
    }
};

