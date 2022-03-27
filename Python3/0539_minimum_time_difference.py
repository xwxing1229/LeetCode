# https://leetcode-cn.com/problems/minimum-time-difference/

class Solution:
    def findMinDifference(self, timePoints):
        """
        Inputs:
            timePoints: list[str]
        Outputs:
            res: int
        """

        # Convert 24-hour time to time in minute.
        minutes = []
        for i in timePoints:
            minute = int(i[0:2]) * 60 + int(i[3:5])
            minutes.append(minute)
        minutes.sort()

        n = len(minutes)
        res = minutes[0] + 24*60 - minutes[n-1]
        for i in range(1,n):
            res = min(res, minutes[i]-minutes[i-1])
        return res