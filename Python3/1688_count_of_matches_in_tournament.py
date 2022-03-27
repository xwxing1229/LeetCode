# https://leetcode-cn.com/problems/count-of-matches-in-tournament/

class Solution:
    def numberOfMatches(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """

        res = 0
        while n > 1:
            match = n // 2
            res = res + match

            n = n - match
        return res