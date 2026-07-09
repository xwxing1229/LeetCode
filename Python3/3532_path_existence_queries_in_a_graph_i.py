# https://leetcode.cn/problems/path-existence-queries-in-a-graph-i/

class Solution:
    def pathExistenceQueries(self, n: int, nums: list[int], maxDiff: int, queries: list[list[int]]) -> list[bool]:
        valid = [i for i in range(n)]
        right = 0
        for i in range(n):
            right = max(i+1, right)
            while right < n and nums[right] - nums[right-1] <= maxDiff:
                right += 1
            valid[i] = right - 1
        
        res = [False for _ in range(len(queries))]
        for i, q in enumerate(queries):
            l, r = min(q), max(q)
            res[i] = r <= valid[l]
        return res