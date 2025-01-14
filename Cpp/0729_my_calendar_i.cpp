// https://leetcode.cn/problems/my-calendar-i/

class MyCalendar {
public:
    MyCalendar() {

    }

    bool book(int startTime, int endTime) {
        calendar_[startTime] += 1;
        calendar_[endTime] -= 1;
        int cnt = 0;
        for (auto it = calendar_.begin(); it != calendar_.end(); ++it) {
            cnt += it->second;
            if (cnt > 1) {
                calendar_[startTime] -= 1;
                calendar_[endTime] += 1;
                return false;
            }
        }
        return true;
    }

    map<int, int> calendar_;
};


/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */
