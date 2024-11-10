# https://leetcode.cn/problems/count-pairs-that-form-a-complete-day-ii/

class Solution:
    def countCompleteDayPairs(self, hours):
        """
        Inputs:
            hours: list[int]
        Outputs:
            res: int
        """
        cnts = [0 for _ in range(24)]
        res = 0
        for h in hours:
            rem = h % 24
            if rem == 0:
                res += cnts[0]
            else:
                res += cnts[24 - rem]
            cnts[rem] += 1
        return res