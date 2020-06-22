/*
 * @lc app=leetcode id=668 lang=cpp
 *
 * [668] Kth Smallest Number in Multiplication Table
 */

// @lc code=start
class Solution {
public:
int findKthNumber(int m, int n, int k) {
    int l = 1, r = m * n;
    while(l < r) {
        int mid = l + (r - l) / 2;
        int rank = count(m, n, mid);
        if(rank < k) l = mid + 1;
        else r = mid;
    }
    return l;
}

int count(int m, int n, int mid) {
    int res = 0;
    for(int i = 1; i <= m; ++i) {
        int l = 1, r = n + 1;
        while(l < r) {
            int t = (l + (r - l) / 2) * i;
            if(t > mid) r = l + (r - l) / 2;
            else l = l + (r - l) / 2 + 1;
        }
        res += l - 1;
    }
    return res;
}
};
// @lc code=end

