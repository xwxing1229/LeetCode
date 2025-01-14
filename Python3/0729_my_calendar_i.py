# https://leetcode.cn/problems/my-calendar-ii/

from sortedcontainers import SortedDict

class MyCalendarTwo:

    def __init__(self):
        self.calendar = SortedDict()

    def book(self, startTime: int, endTime: int) -> bool:
        self.calendar[startTime] = self.calendar.get(startTime, 0) + 1
        self.calendar[endTime] = self.calendar.get(endTime, 0) - 1
        cnt = 0
        for v in self.calendar.values():
            cnt += v
            if cnt > 1:
                self.calendar[startTime] -= 1
                self.calendar[endTime] += 1
                return False
        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(startTime,endTime)