/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */

// @lc code=start
class Solution {
public:
	vector<int> time{1, 2, 4, 8, 16, 32, 60, 120, 240, 480};
	vector<string> res;
    vector<string> readBinaryWatch(int num) {
		helper(0, 0, 0, 0,num);
		return res;
    }
	void helper(int p, int cnt, int n1, int n2, int num) {
		if(p >= time.size() && cnt < num) return;
		if(cnt == num) {
			if(n2 / 60 < 12 && n1 < 60) res.push_back(tostring(n1, n2/60));
			return;
		}
		for(int i = p; i < time.size(); ++i) {
			if(i <= 5) helper(i + 1, cnt + 1, n1 + time[i], n2, num);
			else helper(i + 1, cnt + 1, n1, n2 + time[i], num);
		}
	}
	string tostring(int minute, int hour) {
		stringstream s;
		s << hour << ':';
		if(minute < 10) s << '0';
		s << minute;
		return s.str();
	}
};
// @lc code=end

