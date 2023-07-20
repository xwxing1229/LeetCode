# https://leetcode.cn/problems/alternating-digit-sum/

class Solution:
    def alternateDigitSum(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """
        res = 0
        add, digits = 1, 0
        while n > 0:
            res += add * (n % 10)
            n //= 10
            add = -add
            digits += 1
        if digits % 2 == 0:
            res = -res
        return res