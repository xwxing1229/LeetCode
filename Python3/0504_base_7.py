# https://leetcode.cn/problems/base-7/

class Solution:
    def convertToBase7(self, num):
        """
        Inputs:
            num: int
        Outputs:
            res: str
        """
        if num == 0:
            return "0"
            
        n, neg = num, 0
        if num < 0:
            n, neg = -num, 1
        res = ""
        while n:
            res += str(n % 7)
            n //= 7
        if neg:
            res += "-"
        return res[::-1]