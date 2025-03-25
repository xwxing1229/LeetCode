# https://leetcode.cn/problems/difference-of-number-of-distinct-values-on-diagonals/

from collections import defaultdict

class Solution:
    def differenceOfDistinctValues(self, grid):
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: list[list[int]]
        """
        def update(row, col):
            topleft, bottomright = defaultdict(int), defaultdict(int)
            i, j = row, col
            while i < m and j < n:
                bottomright[grid[i][j]] += 1
                i += 1
                j += 1
            i, j = row, col
            while i < m and j < n:
                val = grid[i][j]
                bottomright[val] -= 1
                if bottomright[val] <= 0:
                    del bottomright[val]

                res[i][j] = abs(len(topleft) - len(bottomright))

                topleft[val] += 1
                i += 1
                j += 1

        m, n = len(grid), len(grid[0])
        res = [[0 for _ in range(n)] for _ in range(m)]
        for row in range(m):
            update(row, 0)
        for col in range(1, n):
            update(0, col)
        return res