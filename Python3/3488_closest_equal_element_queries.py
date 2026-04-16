# https://leetcode.cn/problems/closest-equal-element-queries/

from collections import defaultdict

class Solution:
    def solveQueries(self, nums: list[int], queries: list[int]) -> list[int]:
        position = defaultdict(list)
        for i, num in enumerate(nums):
            position[num].append(i)
        closest = defaultdict(lambda: -1)
        n = len(nums)
        for pos in position.values():
            if len(pos) < 2:
                continue
            for i in range(1, len(pos)-1):
                p = pos[i]
                closest[p] = min(p-pos[i-1], pos[i+1]-p)
            closest[pos[0]] = min(pos[0]+n-pos[-1], pos[1]-pos[0])
            closest[pos[-1]] = min(pos[-1]-pos[-2], pos[0]+n-pos[-1])
        res = [-1 for _ in range(len(queries))]
        for i, q in enumerate(queries):
            res[i] = closest[q]
        return res