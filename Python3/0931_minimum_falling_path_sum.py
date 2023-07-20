# https://leetcode.cn/problems/minimum-falling-path-sum/

class Solution:
    def minFallingPathSum(self, matrix):
        """
        Inputs:
            matrix: list[list[int]]
        Outputs:
            res: int
        """
        n = len(matrix)
        dp = [matrix[0][j] for j in range(n)]
        dp_pre = [matrix[0][j] for j in range(n)]
        for i in range(1, n):
            dp[0] = min(dp_pre[0], dp_pre[1]) + matrix[i][0]
            dp[n-1] = min(dp_pre[n-1], dp_pre[n-2]) + matrix[i][n-1]
            for j in range(1, n-1):
                dp[j] = min(dp_pre[j], min(dp_pre[j-1], dp_pre[j+1])) + matrix[i][j]
            dp_pre = [dp[j] for j in range(n)]
        return min(dp)