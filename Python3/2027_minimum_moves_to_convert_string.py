# https://leetcode.cn/problems/minimum-moves-to-convert-string/

class Solution:
    def minimumMoves(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: int
        """
        res, i = 0, 0
        while i < len(s):
            if s[i] == "X":
                res += 1
                i += 3
            else:
                i += 1
        return res