# https://leetcode.cn/problems/count-days-without-meetings/

class Solution:
    def countDays(self, days, meetings):
        """
        Inputs:
            days: int
            meetings: list[list[int]]
        Outputs:
            res: int
        """
        meetings.sort()
        left, right = meetings[0][0], meetings[0][1]
        res = left - 1
        for ml, mr in meetings:
            if right + 1 < ml:
                res += ml - right - 1
                left = ml
            right = max(right, mr)
        res += days - right
        return res