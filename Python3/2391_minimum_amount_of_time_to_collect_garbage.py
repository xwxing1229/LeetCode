# https://leetcode.cn/problems/minimum-amount-of-time-to-collect-garbage/

class Solution:
    def garbageCollection(self, garbage, travel):
        """
        Inputs:
            garbage: list[str]
            travel: list[int]
        Outputs:
            res: int
        """
        res, n = 0, len(garbage)
        ends = [0,0,0]
        for i in range(n-1, -1, -1):
            g = garbage[i]
            metal = g.count("M")
            paper = g.count("P")
            glass = g.count("G")
            res += metal + paper + glass
            if ends[0] == 0 and metal != 0:
                ends[0] = i
            if ends[1] == 0 and paper != 0:
                ends[1] = i
            if ends[2] == 0 and glass != 0:
                ends[2] = i

        cumtravel = [0 for _ in range(n)]
        for i, t in enumerate(travel):
            cumtravel[i+1] = cumtravel[i] + t
        
        for i in range(3):
            res += cumtravel[ends[i]]
        return res