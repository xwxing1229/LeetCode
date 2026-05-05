# https://leetcode.cn/problems/minimum-operations-to-make-a-uni-value-grid/

class Solution:
    def minOperations(self, grid: list[list[int]], x: int) -> int:
        mod = grid[0][0] % x
        for row in grid:
            for val in row:
                if val % x != mod:
                    return -1

        res = 0
        rows, cols = len(grid), len(grid[0])
        n = rows * cols
        values = [grid[i//cols][i%cols] for i in range(n)]
        values.sort()
        mid = values[n//2]
        for i in range(n):
            res += abs(values[i] -  mid) // x
        return res