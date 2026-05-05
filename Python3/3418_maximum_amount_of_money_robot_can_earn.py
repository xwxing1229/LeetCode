# https://leetcode.cn/problems/maximum-amount-of-money-robot-can-earn/

class Solution:
    def maximumAmount(self, coins: list[list[int]]) -> int:
        m, n = len(coins), len(coins[0])
        dp = [[float("-inf"), float("-inf"), float("-inf")] for _ in range(n)]
        dp[0] = [0,0,0]
        for i in range(m):
            prev = [float("-inf"), float("-inf"), float("-inf")]
            for j in range(n):
                c = coins[i][j]
                dp[j][2] = max(max(dp[j][1], prev[1]),
                               max(dp[j][2], prev[2]) + c)
                dp[j][1] = max(max(dp[j][0], prev[0]),
                               max(dp[j][1], prev[1]) + c)
                dp[j][0] = max(dp[j][0], prev[0]) + c
                prev = dp[j]
        return max(dp[-1])