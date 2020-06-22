/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */
class Solution {
public:
    static bool cmp(const vector<int> &v1, const vector<int> &v2) {
        return v1[0] < v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int sz = intervals.size();
        if(sz == 0) {
            return result;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        result.push_back(intervals[0]);
        for(int i = 1; i < sz; ++i) {
            if(intervals[i][0] <= result[result.size() - 1][1])
                result[result.size() - 1][1] = max(intervals[i][1], result[result.size() - 1][1]);
            else 
                result.push_back(intervals[i]);
        }
        return result;
    }
};

