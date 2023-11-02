# https://leetcode.cn/problems/rings-and-rods/

class Solution:
    def countPoints(self, rings):
        """
        Inputs:
            rings: str
        Outputs:
            res: int
        """
        rods = [dict() for _ in range(10)]
        for i in range(0, len(rings), 2):
            rods[int(rings[i+1])][rings[i]] = 1
        res = 0
        for r in rods:
            if len(r) == 3:
                res += 1
        return res