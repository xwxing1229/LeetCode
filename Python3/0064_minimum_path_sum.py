# https://leetcode-cn.com/problems/minimum-path-sum/

class Solution:
    def minPathSum(self, grid):
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: int
        """
        
        m = len(grid)
        n = len(grid[0])
        dp = [0 for _ in range(n)]
        
        # Initialization.
        dp[0] = grid[0][0]
        for j in range(1,n):
            dp[j] = dp[j-1] + grid[0][j]
            
        # Dynamic programming.
        for i in range(1,m):
            dp[0] = dp[0] + grid[i][0]
            for j in range(1,n):
                dp[j] = min(dp[j-1], dp[j]) + grid[i][j]
        
        res = dp[-1]
        return res