# https://leetcode.cn/problems/knight-probability-in-chessboard/

class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        dirs = [[2,1], [2,-1], [-2,1], [-2,-1], [1,2], [1,-2], [-1,2], [-1,-2]]
        dp = [[[0 for _ in range(n+4)] for _ in range(n+4)] for _ in range(k+1)]
        for i in range(2, n+2):
            for j in range(2, n+2):
                dp[0][i][j] = 1
        for step in range(1, k+1):
            for i in range(2, n+2):
                for j in range(2, n+2):
                    p = 0
                    for d in dirs:
                        p += dp[step-1][i-d[0]][j-d[1]]
                    dp[step][i][j] = p / 8
        return dp[k][row+2][column+2]