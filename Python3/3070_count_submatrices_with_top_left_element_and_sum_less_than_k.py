# https://leetcode.cn/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/

class Solution:
    def countSubmatrices(self, grid: list[list[int]], k: int) -> int:
        res = 0
        m, n = len(grid), len(grid[0])
        dp = [[0 for _ in range(n)] for _ in range(m)]
        dp[0][0] = grid[0][0]
        res += dp[0][0] <= k
        for i in range(1, m):
            dp[i][0] = dp[i-1][0] + grid[i][0]
            res += dp[i][0] <= k
        for j in range(1, n):
            dp[0][j] = dp[0][j-1] + grid[0][j]
            res += dp[0][j] <= k
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + grid[i][j]
                res += dp[i][j] <= k
        return res