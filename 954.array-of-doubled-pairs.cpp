/*
 * @lc app=leetcode id=954 lang=cpp
 *
 * [954] Array of Doubled Pairs
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const int a, const int b) {
        return abs(a) < abs(b) || (a + b == 0 && a < b);
    }
    bool canReorderDoubled(vector<int>& A) {
        sort(A.begin(), A.end(), cmp);
        vector<bool> used(A.size(), false);
        int j = 0;
        for(int i = 0; i < A.size(); ++i) {
            if(used[i]) continue;
            for(j = max(j, i + 1); j < A.size(); ++j) {
                if(used[j] == false && A[j] == A[i] * 2) {
                    used[j] = true;
                    used[i] = true;
                    break;
                }
            }
            if(j == A.size()) return false;
        }
        return true;

    }
};
// @lc code=end

