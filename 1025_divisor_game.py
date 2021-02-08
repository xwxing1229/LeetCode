# https://leetcode-cn.com/problems/divisor-game/

class Solution:
    def divisorGame(self, N):
        """
        Inputs:
            N: int
        Outputs:
            res: bool
        """

        # Induction.
        if N % 2 == 0:
            res = True
        else:
            res = False
        return res