# https://leetcode.cn/problems/count-ways-to-group-overlapping-ranges/
        
class Solution:
    def countWays(self, ranges):
        """
        Inputs:
            ranges: list[list[int]]
        Outputs:
            res: int
        """
        MOD = int(1e9) + 7
        ranges.sort(key=lambda x: (x[0], x[1]))
        groups = 1
        right = ranges[0][1]
        for i, r in enumerate(ranges):
            if r[0] > right:
                groups += 1
                right = r[1]
            else:
                right = max(right, r[1])
                
        res = 1
        for i in range(groups):
            res = res * 2 % MOD
        return res