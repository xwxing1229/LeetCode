# https://leetcode.cn/problems/ugly-number/

class Solution:
    def isUgly(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: bool
        """
        while n > 1:
            if n % 2 == 0:
                n = n / 2
            elif n % 3 == 0:
                n = n / 3
            elif n % 5 == 0:
                n = n / 5
            else:
                break
        if n == 1:
            return True
        else:
            return False