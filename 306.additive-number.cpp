/*
 * @lc app=leetcode id=306 lang=cpp
 *
 * [306] Additive Number
 */
// 用long保存结果, 如果str长度大于19则break(long溢出)
// @lc code=start
class Solution {
public:
    bool isAdditiveNumber(string num) {
        bool res = false;
        vector<long> out;
        helper(num, 0, out, res);
        return res;
    }
    void helper(string& num, int start, vector<long>& out, bool& res) {
        if (res) return;
        if (start >= num.size()) {
            if (out.size() >= 3) res = true; 
            return;
        }
        for (int i = start; i < num.size(); ++i) {
            string str = num.substr(start, i - start + 1);
            if ((str.size() > 1 && str[0] == '0') || str.size() > 19) break;
            long curNum = stol(str), n = out.size();
            if (out.size() >= 2 && curNum != out[n - 1] + out[n - 2]) continue;
            out.push_back(curNum);
            helper(num, i + 1, out, res);
            out.pop_back();
        }
    }
};
// @lc code=end

