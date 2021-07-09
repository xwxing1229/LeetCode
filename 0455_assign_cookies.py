# https://leetcode-cn.com/problems/assign-cookies/

class Solution:
    def findContentChildren(self, g, s):
        """
        Inputs:
            g: list[int]
            s: list[int]
        Outputs:
            res: int
        """

        g.sort()
        s.sort()

        res = 0
        idx = 0
        n = len(s)
        for child in g:
            while idx < n and child > s[idx]:
                idx = idx + 1
            if idx >= n:
                break

            res = res + 1
            idx = idx + 1
        return res