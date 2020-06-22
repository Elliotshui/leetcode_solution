/*
 * @lc app=leetcode id=991 lang=cpp
 *
 * [991] Broken Calculator
 */

// @lc code=start
class Solution {
public:
   int brokenCalc(int X, int Y) {
        if(X>Y)return X-Y;
        int res=0;
        while(X<Y){
            if(Y%2==1){
                Y++;
            }else{
                Y/=2;
            }
            res++;
        }
        return res+X-Y;
    }

};
// @lc code=end

