# https://leetcode.cn/problems/stone-game-vii/

class Solution:
    def stoneGameVII(self, stones):
        """
        Inputs:
            stones: list[int]
        Outputs:
            res: int
        """
        n = len(stones)
        cumsum = [0 for _ in range(n+1)]
        for i, stone in enumerate(stones):
            cumsum[i+1] = cumsum[i] + stone
        
        dp = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(n-2, -1, -1):
            for j in range(i+1, n):
                dp[i][j] = max(cumsum[j+1] - cumsum[i+1] - dp[i+1][j],
                               cumsum[j] - cumsum[i] - dp[i][j-1])
        return dp[0][n-1]