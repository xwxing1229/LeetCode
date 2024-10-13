# https://leetcode.cn/problems/destination-city/

class Solution:
    def destCity(self, paths):
        """
        Inputs:
            paths: list[list[str]]
        Outputs:
            res: str
        """
        s = set()
        for a, b in paths:
            s.add(b)
        for a, b in paths:
            s.discard(a)
        return s.pop()