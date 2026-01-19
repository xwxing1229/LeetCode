# https://leetcode.cn/problems/largest-magic-square/

class Solution:
    def largestMagicSquare(self, grid: list[list[int]]) -> int:
        m, n = len(grid), len(grid[0])
        cs_row = [[0 for _ in range(n+1)] for _ in range(m)]
        cs_col = [[0 for _ in range(n)] for _ in range(m+1)]
        cs_diag = [[0 for _ in range(n+1)] for _ in range(m+1)]
        cs_anti = [[0 for _ in range(n+1)] for _ in range(m+1)]
        for i in range(m):
            for j in range(n):
                cs_row[i][j+1] = cs_row[i][j] + grid[i][j]
                cs_col[i+1][j] = cs_col[i][j] + grid[i][j]
                cs_diag[i+1][j+1] = cs_diag[i][j] + grid[i][j]
        for i in range(m):
            for j in range(n-1, -1, -1):
                cs_anti[i+1][j] = cs_anti[i][j+1] + grid[i][j]
        for row in cs_anti:
            print(row)
        res = 0
        for i in range(m):
            for j in range(n):
                k_min = res + 1
                k_max = min(m-i, n-j)
                for k in range(k_min, k_max+1):
                    s = cs_diag[i+k][j+k] -cs_diag[i][j]
                    if s != cs_anti[i+k][j] - cs_anti[i][j+k]:
                        continue
                    valid = True
                    for t in range(k):
                        if s != cs_row[i+t][j+k] - cs_row[i+t][j]:
                            valid = False
                            break
                        if s != cs_col[i+k][j+t] - cs_col[i][j+t]:
                            valid = False
                            break
                    if valid:
                        res = k
        return res