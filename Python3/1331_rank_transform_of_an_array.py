# https://leetcode.cn/problems/rank-transform-of-an-array/

class Solution:
    def arrayRankTransform(self, arr: list[int]) -> list[int]:
        arr_sort = sorted(set(arr))
        rank = {x: i for i, x in enumerate(arr_sort, 1)}
        res = [0 for _ in range(len(arr))]
        for i, x in enumerate(arr):
            res[i] = rank[x]
        return res