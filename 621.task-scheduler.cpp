/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
// 若不存在idle, 则t = len
// 若存在idle, 则一定为ABCDE(idle)ABCD(idle)ABCD(idle)ABC的形式, 其中ABC是出现次数最多的任务
// 比较两者较大的即可
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (char task : tasks) {
            ++cnt[task - 'A'];
        }
        sort(cnt.begin(), cnt.end());
        int i = 25, mx = cnt[25], len = tasks.size();
        while (i >= 0 && cnt[i] == mx) --i;
        return max(len, (mx - 1) * (n + 1) + 25 - i);
    }
};
// @lc code=end

