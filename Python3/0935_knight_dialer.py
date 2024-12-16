# https://leetcode.cn/problems/knight-dialer/

class Solution:
    def knightDialer(self, n: int) -> int:
        def invalid(i, j):
            return i == 3 and (j == 0 or j == 2)
        
        MOD = int(1e9) + 7
        dirs = [[1,2], [1,-2], [-1,2], [-1,-2], [2,1], [2,-1], [-2,1], [-2,-1]]
        dp = [[[0 for _ in range(7)] for _ in range(8)] for _ in range(n)]
        for i in range(2, 6):
            for j in range(2, 5):
                if invalid(i-2, j-2):
                    continue
                dp[0][i][j] = 1

        for k in range(1, n):
            for i in range(2, 6):
                for j in range(2, 5):
                    if invalid(i-2, j-2):
                        continue
                    tmp = 0
                    for d in dirs:
                        tmp = (tmp + dp[k-1][i+d[0]][j+d[1]]) % MOD
                    dp[k][i][j] = tmp
        
        res = 0
        for row in dp[n-1]:
            for cnt in row:
                res = (res + cnt) % MOD
        return res