/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */

// @lc code=start
class Solution {
public:
int maximumSwap(int num) {
    vector<int> digits;
    int tmp = num;
    while(tmp > 0) {
        digits.push_back(tmp % 10);
        tmp = tmp / 10;
    }
    vector<int> digits_o = digits;
    sort(digits.begin(), digits.end());
    int i = digits.size() - 1;
    while(i >= 0 && digits[i] == digits_o[i]) i--;
    if(i < 0)   return num;
    for(int j = 0; j < digits.size(); ++j) {
        if(digits_o[j] == digits[i]) {
            digits_o[j] = digits_o[i];
            break;
        }
    }
    digits_o[i] = digits[i];
    
    int res = 0;
    for(int j = digits_o.size() - 1; j >= 0; --j) {
        res = res * 10 + digits_o[j];
    }
    return res;
}
};
// @lc code=end

