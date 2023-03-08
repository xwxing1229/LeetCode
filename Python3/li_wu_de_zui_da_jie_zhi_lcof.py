# https://leetcode.cn/problems/largest-local-values-in-a-matrix/

class Solution:
    def maxValue(self, grid):
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: int
        """
        rows, cols = len(grid), len(grid[0])
        dp = [0 for _ in range(cols)]
        for i in range(rows):
            dp[0] += grid[i][0]
            for j in range(1, cols):
                dp[j] = max(dp[j-1], dp[j]) + grid[i][j]
        return dp[cols-1]