# https://leetcode.cn/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/

class Solution:
    def minCost(self, startPos: list[int], homePos: list[int], rowCosts: list[int], colCosts: list[int]) -> int:
        res = 0
        step = [1 if startPos[i] <= homePos[i] else -1 for i in range(2)]
        for i in range(homePos[0], startPos[0], -step[0]):
            res += rowCosts[i]
        for i in range(homePos[1], startPos[1], -step[1]):
            res += colCosts[i]
        return res