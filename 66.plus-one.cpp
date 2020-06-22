/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sz = digits.size();
        for(int i = sz - 1; i >= 0; --i) {
            if(digits[i] != 9) {
                digits[i] += 1;
                return digits;
            }
            else {
                digits[i] = 0;
            }
        }
        vector<int> result;
        result.push_back(1);
        for(int i = 0; i < sz; ++i) {
            result.push_back(0);
        }
        return result;
    }
};

