# https://leetcode.cn/problems/count-asterisks/

class Solution:
    def countAsterisks(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: str
        """
        res, inside = 0, 0
        for ch in s:
            if ch == "|":
                inside = 1 - inside
            elif ch == "*" and not inside:
                res += 1
        return res