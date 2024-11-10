# https://leetcode.cn/problems/number-of-students-doing-homework-at-a-given-time/

class Solution:
    def busyStudent(self, startTime, endTime, queryTime):
        """
        Inputs:
            startTime: list[int]
            endTime: list[int]
            queryTime: int
        Outputs:
            res: int
        """
        res = 0
        for i, start in enumerate(startTime):
            if queryTime >= start and queryTime <= endTime[i]:
                res += 1
        return res