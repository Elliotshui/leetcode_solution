/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start
class MyCalendar {
public:

    struct date {
        int start, end;
        date(int s, int e) {
            start = s;
            end = e;
        }
        bool operator < (const date& d) const {
            return end <= d.start;
        }
    };
    set<date> dates;
    MyCalendar() {
        
    }
    bool book(int start, int end) {
        date newdate = date(start, end);
        if(dates.count(newdate))
            return false;
        else {
            dates.insert(newdate);
            return true;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

