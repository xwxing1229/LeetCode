# https://leetcode.cn/problems/maximum-split-of-positive-even-integers/

class Solution:
    def maximumEvenSplit(self, finalSum):
        """
        Inputs:
            finalSum: int
        Outputs:
            res: list[int]
        """
        res = []
        if finalSum % 2 == 1:
            return res
        cur = 2
        while finalSum > 0:
            res.append(cur)
            finalSum -= cur
            cur += 2
            if finalSum < cur:
                res[-1] += finalSum
                finalSum = 0
        return res