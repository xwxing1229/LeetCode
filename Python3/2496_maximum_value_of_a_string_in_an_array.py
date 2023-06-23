# https://leetcode.cn/problems/maximum-value-of-a-string-in-an-array/

class Solution:
    def maximumValue(self, strs):
        """
        Inputs:
            strs: list[int]
        Outputs:
            res: int
        """
        res = 0
        for s in strs:
            if s.isdigit() and int(s) > res:
                res = int(s)
            elif not s.isdigit() and len(s) > res:
                res = len(s)
        return res