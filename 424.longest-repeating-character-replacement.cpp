/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
//O(N)时间复杂度, maxcnt不用减小
class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0, maxCnt = 0, start = 0;
        vector<int> counts(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            maxCnt = max(maxCnt, ++counts[s[i] - 'A']);
            while (i - start + 1 - maxCnt > k) {
                --counts[s[start] - 'A'];
                ++start;
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
	/*
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int r = 0, len = s.length();
        int res = 0;
        for(int l = 0; l < len; ++l) {
            while(r < len) {
                cnt[s[r] - 'A']++;
                int maxcnt = findmax(cnt);
                if(r - l + 1 - maxcnt > k) {
                    cnt[s[r] - 'A']--;
                    break;
                }
                r++;
            }
            if(r - l > res) res = r - l;
            cnt[s[l] - 'A']--;
        }
        return res;
    }
    int findmax(const vector<int> &cnt) {
        int res = 0;
        for(int i = 0; i < cnt.size(); ++i) {
            res = max(res, cnt[i]);
        }
		return res;
    }
	*/
};
// @lc code=end

