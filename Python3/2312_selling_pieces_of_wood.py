# https://leetcode.cn/problems/selling-pieces-of-wood/

class Solution:
    def sellingWood(self, m, n, prices):
        """
        Inputs:
            m, n: int
            prices: list[list[int]]
        Outputs:
            res: int
        """
        dp = [[0 for _ in range(n+1)] for _ in range(m+1)]
        for h, w, p in prices:
            dp[h][w] = p
        for row in range(1, m+1):
            for col in range(1, n+1):
                for i in range(1, row):
                    dp[row][col] = max(dp[row][col], dp[i][col] + dp[row-i][col])
                for j in range(1, col):
                    dp[row][col] = max(dp[row][col], dp[row][j] + dp[row][col-j])
        return dp[m][n]