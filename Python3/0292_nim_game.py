# https://leetcode.cn/problems/nim-game/

class Solution:
    def canWinNim(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: bool
        """
        if n % 4 == 0:
            return False
        else:
            return True