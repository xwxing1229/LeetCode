# https://leetcode.cn/problems/elimination-game/

class Solution:
    def lastRemaining(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """

        if n == 1:
            return n

        return 2 * (n//2 + 1 - self.lastRemaining(n//2))