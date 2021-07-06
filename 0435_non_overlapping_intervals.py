# https://leetcode-cn.com/problems/non-overlapping-intervals/

class Solution:
    def eraseOverlapIntervals(self, intervals):
        """
        Inputs:
            intervals: list[list[int]]
        Outputs:
            res: int
        """

        intervals.sort(key=lambda x:x[1])
        n = len(intervals)

        # Count how many intervals that meet the requirement.
        count = 1
        right = intervals[0][1]
        for i in range(1,n):
            if intervals[i][0] >= right:
                count = count + 1
                right = intervals[i][1]

        return n - count