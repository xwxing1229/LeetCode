# https://leetcode.cn/problems/minimum-moves-to-reach-target-with-rotations/

class Solution:
    def minimumMoves(self, grid):
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: int
        """
        n = len(grid)
        dp = [[[float("inf"), float("inf")] for j in range(n)] for i in range(n)]
        dp[0][0][0] = 0

        for i in range(n):
            for j in range(n):
                can_horizontal = (j + 1 < n and grid[i][j] == grid[i][j+1] == 0)
                can_vertical = (i + 1 < n and grid[i][j] == grid[i+1][j] == 0)

                if i - 1 >= 0 and can_horizontal:
                    dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][0] + 1)
                if j - 1 >= 0 and can_horizontal:
                    dp[i][j][0] = min(dp[i][j][0], dp[i][j-1][0] + 1)
                if i - 1 >= 0 and can_vertical:
                    dp[i][j][1] = min(dp[i][j][1], dp[i-1][j][1] + 1)
                if j - 1 >= 0 and can_vertical:
                    dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1] + 1)
                
                if can_horizontal and can_vertical and grid[i+1][j+1] == 0:
                    dp[i][j][0] = min(dp[i][j][0], dp[i][j][1] + 1)
                    dp[i][j][1] = min(dp[i][j][1], dp[i][j][0] + 1)
        
        if dp[n-1][n-2][0] == float("inf"):
            return -1
        else:
            return dp[n-1][n-2][0]