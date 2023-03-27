# https://leetcode.cn/problems/teemo-attacking/

class Solution:
    def findPoisonedDuration(self, timeSeries, duration):
        """
        Inputs:
            timeSeries: list[int]
            duration: int
        Outputs:
            res: int
        """
        res = 0
        start, end = timeSeries[0], timeSeries[0] + duration
        for i in range(1, len(timeSeries)):
            if end < timeSeries[i]:
                res += (end - start)
                start = timeSeries[i]
            end = timeSeries[i] + duration
        res += (end - start)
        return res