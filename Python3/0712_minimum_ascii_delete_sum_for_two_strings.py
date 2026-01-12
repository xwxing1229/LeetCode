# https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/

class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        n1, n2 = len(s1), len(s2)
        dp = [[0 for _ in range(n2 + 1)] for _ in range(n1 + 1)]
        for i1 in range(1, n1+1):
            dp[i1][0] = dp[i1-1][0] + ord(s1[i1-1])
        for i2 in range(1, n2+1):
            dp[0][i2] = dp[0][i2-1] + ord(s2[i2-1])
        for i1 in range(1, n1+1):
            for i2 in range(1, n2+1):
                if s1[i1-1] == s2[i2-1]:
                    dp[i1][i2] = dp[i1-1][i2-1]
                else:
                    dp[i1][i2] = min(dp[i1-1][i2] + ord(s1[i1-1]),
                                     dp[i1][i2-1] + ord(s2[i2-1]))
        return dp[n1][n2]