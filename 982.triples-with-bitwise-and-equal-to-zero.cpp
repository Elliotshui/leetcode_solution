/*
 * @lc app=leetcode id=982 lang=cpp
 *
 * [982] Triples with Bitwise AND Equal To Zero
 */

// @lc code=start
class Solution {
public:
    int countTriplets(vector<int>& A) {
        const int N = A.size();
        int res = 0;
        unordered_map<int, int> m_;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                ++m_[(A[i] & A[j])];
            }
        }
        for (int i = 0; i < N; ++i) {
            for (auto a : m_) {
                if ((A[i] & a.first) == 0)
                    res += a.second;
            }
        }
        return res;

    }
};
// @lc code=end

