# https://leetcode.cn/problems/pass-the-pillow/

class Solution:
    def passThePillow(self, n, time):
        """
        Inputs:
            n, time: int
        Outputs:
            res: int
        """
        rem = time % (n+n-2)
        res = 1 + rem
        if rem >= n:
            res = n + n - 1 - rem
        return res