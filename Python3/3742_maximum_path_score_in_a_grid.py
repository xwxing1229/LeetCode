# https://leetcode.cn/problems/maximum-path-score-in-a-grid/

class Solution:
    def maxPathScore(self, grid: list[list[int]], k: int) -> int:
        # dp[i][j][c]: maximum score obtained at grid[i][j] with cost c
        # Optimize space complexity.
        m, n = len(grid), len(grid[0])
        dp = [[-1 for _ in range(k+1)] for _ in range(n)]
        dp[0][0] = grid[0][0]
        for j in range(1, n):
            cost = 0 if grid[0][j] == 0 else 1
            for c in range(cost, min(j,k)+1):
                if dp[j-1][c-cost] >= 0:
                    dp[j][c] = max(dp[j][c], dp[j-1][c-cost] + grid[0][j])
        for i in range(1, m):
            dp_curr = [[-1 for _ in range(k+1)] for _ in range(n)]
            for j in range(n):
                cost = 0 if grid[i][j] == 0 else 1
                for c in range(cost, min(i+j,k)+1):
                    if dp[j][c-cost] >= 0:
                        dp_curr[j][c] = max(dp_curr[j][c], dp[j][c-cost] + grid[i][j])
                    if j > 0 and dp_curr[j-1][c-cost] >= 0:
                        dp_curr[j][c] = max(dp_curr[j][c], dp_curr[j-1][c-cost] + grid[i][j])

            dp = dp_curr.copy()
        return max(dp[n-1])

        
        # # dp[i][j][c]: maximum score obtained at grid[i][j] with cost c
        # m, n = len(grid), len(grid[0])
        # dp = [[[-1] * (k + 1) for _ in range(n)] for _ in range(m)]
        # dp[0][0][0] = grid[0][0]
        # for i in range(m):
        #     for j in range(n):
        #         cost = 0 if grid[i][j] == 0 else 1
        #         for c in range(cost, min(i+j, k) + 1):
        #             if i > 0 and dp[i-1][j][c-cost] >= 0:
        #                 dp[i][j][c] = max(dp[i][j][c], dp[i-1][j][c-cost] + grid[i][j])
        #             if j > 0 and dp[i][j - 1][c - cost] >= 0:
        #                 dp[i][j][c] = max(dp[i][j][c], dp[i][j-1][c-cost] + grid[i][j])
        # return max(dp[m - 1][n - 1])