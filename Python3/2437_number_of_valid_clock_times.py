# https://leetcode.cn/problems/number-of-valid-clock-times/

class Solution:
    def countTime(self, time):
        """
        Inputs:
            time: str
        Outputs:
            res: int
        """
        res = 0
        if time[0] == "?":
            if time[1] == "?":
                res = 24
            else:
                for i in range(3):
                    if i * 10 + int(time[1]) < 24:
                        res += 1
        else:
            if time[1] == "?":
                for i in range(10):
                    if int(time[0]) * 10 + i < 24:
                        res += 1
            else:
                res = 1
        if time[3] == "?":
            res *= 6
        if time[4] == "?":
            res *= 10
        return res