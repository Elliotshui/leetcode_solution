/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */
// 若s1 + s2 == s2 + s1, 则s1, s2的gcd子串长度为s1, s2长度的gcd, 可证明
// @lc code=start
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1) {
            return "";
        }
        int l1 = min(str1.length(), str2.length()), l2 = max(str1.length(), str2.length());
        while(l1 > 0) {
            int tmp1 = l2 - l1, tmp2 = l1;
            l1 = min(tmp1, tmp2);
            l2 = max(tmp1, tmp2);
        }
        return str1.substr(0, l2);
    }
};
// @lc code=end

