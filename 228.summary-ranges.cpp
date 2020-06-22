/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution {
public:
vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    vector<int> tmp;
    for(int i = 0; i < nums.size(); ++i) {
        if(tmp.empty()) tmp.push_back(nums[i]);
        else {
            int last = tmp.back();
            if(last + 1 == nums[i])
                tmp.push_back(nums[i]);
            else {
                stringstream s;
                s << tmp.front();
                if(tmp.size() != 1)
                    s << "->" << tmp.back();
                res.push_back(s.str());
                tmp.clear();
                tmp.push_back(nums[i]);
            }
        }
    }
    if(!tmp.empty()) {
        stringstream s;
        s << tmp.front();
        if(tmp.size() != 1)
            s << "->" << tmp.back();
        res.push_back(s.str());
    }
    return res;
}
};
// @lc code=end

