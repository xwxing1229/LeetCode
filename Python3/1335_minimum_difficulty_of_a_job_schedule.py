# https://leetcode.cn/problems/minimum-difficulty-of-a-job-schedule/

class Solution:
    def minDifficulty(self, jobDifficulty, d):
        """
        Inputs:
            jobDifficulty: list[int]
            d: int
        Outputs:
            res: int
        """
        n = len(jobDifficulty)
        if n < d:
            return -1

        # dp[i][j]: minimum difficulty until the ith day with the jth jobs done
        # dp[i][j] = min_{k=i-1, ..., j-1} (dp[i-1][k] + f(k+1, j)),
        # where f(k,j) = max(jobDifficulty[k], ..., jobDifficulty[j]).
        f = [[0 for j in range(n)] for k in range(n)]
        for k in range(n):
            f[k][k] = jobDifficulty[k]
            for j in range(k+1, n):
                f[k][j] = max(f[k][j-1], jobDifficulty[j])
        dp = [[0 for j in range(n)] for i in range(d)]
        for j in range(n):
            dp[0][j] = f[0][j]
        for i in range(1, d):
            for j in range(i, n):
                dp[i][j] = dp[i-1][i-1] + f[i][j]
                for k in range(i, j):
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + f[k+1][j])
        return dp[d-1][n-1]