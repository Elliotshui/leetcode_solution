/*
 * @lc app=leetcode id=1013 lang=cpp
 *
 * [1013] Partition Array Into Three Parts With Equal Sum
 */

// @lc code=start
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        if(sum % 3 != 0) return false;
        for(int i = 0; i < A.size(); ++i) {
            sum += A[i];
        }
        int tmp = 0;
        int i, j;
        for(i = 0; i < A.size(); ++i) {
            tmp += A[i];
            if(tmp == sum / 3) {
                tmp = 0;
                break;
            }
        }
        if(i > A.size() - 3) return false;
        for(j = i + 1; j < A.size(); ++j) {
            tmp += A[j];
            if(tmp == sum / 3) {
                break;
            }
        }
        if(j > A.size() - 2) return false;
        return true;
    }
};
// @lc code=end

