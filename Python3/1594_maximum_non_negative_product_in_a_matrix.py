# https://leetcode.cn/problems/maximum-non-negative-product-in-a-matrix/

class Solution:
    def maxProductPath(self, grid: list[list[int]]) -> int:
        mod = int(1e9 + 7)
        m, n = len(grid), len(grid[0])
        dp = [[[grid[0][0],grid[0][0]] for _ in range(n)] for _ in range(m)]
        for i in range(1, m):
            dp[i][0][0] = dp[i-1][0][0] * grid[i][0]
            dp[i][0][1] = dp[i][0][0]
        for j in range(1, n):
            dp[0][j][0] = dp[0][j-1][0] * grid[0][j]
            dp[0][j][1] = dp[0][j][0]
        for i in range(1, m):
            for j in range(1, n):
                values = [0 for _ in range(4)]
                for k in range(2):
                    values[k] = dp[i-1][j][k] * grid[i][j]
                    values[k+2] = dp[i][j-1][k] * grid[i][j]
                dp[i][j][0] = min(values)
                dp[i][j][1] = max(values)
        return dp[-1][-1][1] % mod if dp[-1][-1][1] >= 0 else -1