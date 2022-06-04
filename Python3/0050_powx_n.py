# https://leetcode.cn/problems/powx-n/

class Solution:
    def myPow(self, x, n):
        """
        Inputs:
            x: float
            n: int
        Outputs:
            res: float
        """

        if x == 0:
            return 0.

        if n >= 0:
            return self.myPowPositive(x, n)
        else:
            return 1. / self.myPowPositive(x, -n)

    def myPowPositive(self, x, n):
        if n == 0:
            return 1.
        else:
            index = n // 2
            rt = self.myPowPositive(x, index)
            if n == 2 * index:
                return rt * rt
            else:
                return rt * rt * x