/*
 * @lc app=leetcode id=936 lang=cpp
 *
 * [936] Stamping The Sequence
 */

// @lc code=start
class Solution {
public:

    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans, output;
        string aim(target.length(), '?');
        while(target != aim)
        {
            int t = moveAstamp(stamp, target);
            if(t == -1)
            {
                return {};
            }
            ans.push_back(t);
        }
        for(int i = ans.size()-1; i >= 0; i--)
            output.push_back(ans[i]);
        return output;
    }
     
    int moveAstamp(string stamp, string &target){
         
        for(int i = 0; i < target.length(); i++)
        {
            int j = 0, k = i;
            bool flag = false;
            while(j < stamp.length() && k < target.length() && (stamp[j] == target[k] || target[k] == '?'))
            {
                if(stamp[j] == target[k])
                    flag = true;
                j++;
                k++;
            }
            if(j == stamp.length() && flag)
            {
                for(int t = i; t < k; t++)
                {
                    target[t] = '?';
                }
                return i;
            }
        }
        return -1;
    }
    
};
// @lc code=end

