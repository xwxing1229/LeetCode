# https://leetcode.cn/problems/insert-interval/

class Solution:
    def insert(self, intervals, newInterval):
        """
        Inputs:
            intervals: list[list[int]]
            newInterval: list[int]
        Outputs:
            res: list[list[int]]
        """

        res = []
        left, right = newInterval
        inserted = False
        for i in range(len(intervals)):
            if intervals[i][0] > right:
                if not inserted:
                    res.append([left, right])
                    inserted = True
                res.append(intervals[i])
            elif intervals[i][1] < left:
                res.append(intervals[i][1])
            else:
                left = min(intervals[i][0], left)
                right = max(intervals[i][1], right)
        if not inserted:
            res.append([left, right])

        return res