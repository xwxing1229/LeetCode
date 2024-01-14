# https://leetcode.cn/problems/day-of-the-year/

class Solution:
    def dayOfYear(self, date):
        """
        Inputs:
            date: str
        Outputs:
            res: int
        """
        days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        yy = int(date[:4])
        mm = int(date[5:7])
        dd = int(date[8:10])
        res = sum(days[:mm-1]) + dd
        if (yy % 400 == 0 or (yy % 4 == 0 and yy % 100 != 0)) and mm > 2:
            res += 1
        return res