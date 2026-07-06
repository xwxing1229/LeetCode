# https://leetcode.cn/problems/remove-covered-intervals/

class Solution:
    def removeCoveredIntervals(self, intervals: list[list[int]]) -> int:
        res = len(intervals)
        intervals.sort(key=lambda x: (x[0], -x[1]))
        right_max = intervals[0][1] - 1
        for interval in intervals:
            if interval[1] <= right_max:
                res -= 1
            right_max = max(right_max, interval[1])
        return res