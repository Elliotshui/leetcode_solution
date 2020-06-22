/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits == "")
            return ret;
            
        ret.push_back("");
        
        vector<string> dict(10); //0~9
        dict[2] = "abc";
        dict[3] = "def";
        dict[4] = "ghi";
        dict[5] = "jkl";
        dict[6] = "mno";
        dict[7] = "pqrs";
        dict[8] = "tuv";
        dict[9] = "wxyz";
        
        for(int i = 0; i < digits.size(); i ++)
        {
            int size = ret.size();
            for(int j = 0; j < size; j ++)
            {
                string cur = ret[0];
                ret.erase(ret.begin());
                for(int k = 0; k < dict[digits[i]-'0'].size(); k ++)
                {
                    ret.push_back(cur + dict[digits[i]-'0'][k]);
                }
            }
        }
        return ret;
    }
};
// @lc code=end

