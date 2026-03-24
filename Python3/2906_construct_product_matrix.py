# https://leetcode.cn/problems/construct-product-matrix/

class Solution:
    def constructProductMatrix(self, grid: list[list[int]]) -> list[list[int]]:
        mod = 12345
        m, n = len(grid), len(grid[0])
        res = [[0 for _ in range(n)] for _ in range(m)]

        suffix = 1
        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                res[i][j] = suffix
                suffix = suffix * grid[i][j] % mod
        prefix = 1
        for i in range(m):
            for j in range(n):
                res[i][j] = res[i][j] * prefix % mod
                prefix = prefix * grid[i][j] % mod
        return res