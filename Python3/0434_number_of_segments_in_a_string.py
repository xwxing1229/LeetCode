# https://leetcode.cn/problems/number-of-segments-in-a-string/

class Solution:
    def countSegments(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: int
        """
        res, n = 0, len(s)
        if n == 0:
            return res

        pre = s[0]
        for i in range(1, n):
            if s[i] == " " and pre != " ":
                res += 1
            pre = s[i]
        if s[n-1] != " ":
            res += 1
        return res
