# https://leetcode.cn/problems/count-numbers-with-unique-digits/

class Solution:
    def countNumbersWithUniqueDigits(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """

        res = 1
        for i in range(n):
            tmp = 9
            for j in range(i):
                tmp = tmp * (9-j)
            res = res + tmp
        return res