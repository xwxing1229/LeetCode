# https://leetcode.cn/problems/stone-game-ii/

class Solution:
    def stoneGameII(self, piles):
        """
        Inputs:
            piles: list[int]
        Outputs:
            res: int
        """
        n, s =  len(piles), 0
        dp = [[0 for m in range(n+1)] for i in range(n)]
        for i in range(n-1, -1, -1):
            s += piles[i]
            for m in range(1, i//2+2):
                if i + 2 * m >= n:
                    dp[i][m] = s
                else:
                    for x in range(1, 2*m+1):
                        dp[i][m] = max(dp[i][m], s - dp[i+x][max(m, x)])
        return dp[0][1]