# https://leetcode.cn/problems/number-of-senior-citizens/

class Solution:
    def countSeniors(self, details):
        """
        Inputs:
            details: list[int]
        Outouts:
            res: int
        """
        res = 0
        for s in details:
            if int(s[11:13]) > 60:
                res += 1
        return res