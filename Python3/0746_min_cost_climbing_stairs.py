# https://leetcode.cn/problems/min-cost-climbing-stairs/

class Solution:
    def minCostClimbingStairs(self, cost):
        """
        Inputs:
            cost: list[int]
        Outputs:
            res: int
        """
        n = len(cost)
        dp = [0 for _ in range(n+1)]
        for i in range(2, n+1):
            dp[i] = min(dp[i-2]+cost[i-2], dp[i-1]+cost[i-1])
        return dp[-1]