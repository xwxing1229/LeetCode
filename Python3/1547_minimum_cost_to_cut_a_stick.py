# https://leetcode.cn/problems/minimum-cost-to-cut-a-stick/

class Solution:
    def minCost(self, n, cuts):
        """
        Inputs:
            n: int
            cuts: list[int]
        Outputs:
            res: int
        """
        cuts.sort()
        cuts = [0] + cuts + [n]

        m = len(cuts)
        dp = [[0 for _ in range(m)] for _ in range(m)]
        for i in range(m-3, -1, -1):
            for j in range(i+2, m):
                tmp = dp[i][i+1] + dp[i+1][j]
                for k in range(i+1, j):
                    tmp = min(tmp, dp[i][k] + dp[k][j])
                dp[i][j] = tmp + cuts[j] - cuts[i]
        return dp[0][-1]