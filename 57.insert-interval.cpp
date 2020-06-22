/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int sz = intervals.size();

        bool flag = false;
        for(int i = 0; i < sz; ++i) {
            if(intervals[i][1] < newInterval[0]) 
                result.push_back(intervals[i]);
            else if(intervals[i][0] > newInterval[1]) {
                if(flag == false) {
                    result.push_back(newInterval);
                    flag = true;
                }
                result.push_back(intervals[i]);
            }
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        if(flag == false)
            result.push_back(newInterval);
        return result;
    }
};

