# https://leetcode.cn/problems/count-submatrices-with-equal-frequency-of-x-and-y/

class Solution:
    def numberOfSubmatrices(self, grid: list[list[str]]) -> int:
        res = 0
        m, n = len(grid), len(grid[0])
        # dp[j][0]: count of "X" in the jth column.
        # dp[j][1]: count of "Y" in the jth column.
        dp = [[0,0] for _ in range(n)]
        table = {"X": 0, "Y": 1}
        for i in range(m):
            cntx, cnty = 0, 0
            for j in range(n):
                ch = grid[i][j]
                if ch != ".":
                    dp[j][table[ch]] += 1
                cntx += dp[j][0]
                cnty += dp[j][1]
                if cntx > 0 and cntx == cnty:
                    res += 1
        return res