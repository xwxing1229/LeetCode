# https://leetcode.cn/problems/WHnhjV/

class Solution:
    def giveGem(self, gem, operations):
        """
        Inputs:
            gem: list[int]
            operations: list[list[int]]
        Outputs:
            res: int
        """
        for op1, op2 in operations:
            n = gem[op1] // 2
            gem[op1] -= n
            gem[op2] += n
        min_, max_ = gem[0], gem[0]
        for g in gem:
            min_ = min(min_, g)
            max_ = max(max_, g)
        return max_ - min_