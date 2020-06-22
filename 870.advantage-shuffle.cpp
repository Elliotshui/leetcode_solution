/*
 * @lc app=leetcode id=870 lang=cpp
 *
 * [870] Advantage Shuffle
 */

// @lc code=start
class Solution {
public:
struct B_idx{
    int B, idx;
    bool operator < (const B_idx& B1) const {
        return B > B1.B;
    }
    B_idx(int B_, int idx_): B(B_), idx(idx_) {}
};
vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    vector<B_idx> setB;
    vector<int> res(B.size(), 0);
    for(int i = 0; i < B.size(); ++i) {
        setB.push_back(B_idx(B[i], i));
    }
    sort(A.begin(), A.end());
    sort(setB.begin(), setB.end());
    int l = 0, r = A.size() - 1;
    for(auto it = setB.begin(); it != setB.end(); ++it) {
        if(A[r] <= it->B) {
            res[it->idx] = A[l];
            l++;
        }
        else {
            res[it->idx] = A[r];
            r--;
        }
    }
    return res;
}
};
// @lc code=end

