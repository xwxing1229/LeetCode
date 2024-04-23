# https://leetcode.cn/problems/grumpy-bookstore-owner/

class Solution:
    def maxSatisfied(self, customers, grumpy, minutes):
        """
        Inputs:
            customers, grumpy: list[int]
            minutes: int
        Outputs:
            res: int
        """
        n = len(customers)
        dp = [0 for _ in range(n-minutes+1)]
        for i in range(minutes):
            dp[0] += customers[i]
        for i in range(minutes, n):
            if grumpy[i] == 0:
                dp[0] += customers[i]

        res = dp[0]
        for i in range(1, len(dp)):
            dp[i] = dp[i-1]
            if grumpy[i-1] == 1:
                dp[i] -= customers[i-1]
            if grumpy[i+minutes-1] == 1:
                dp[i] += customers[i+minutes-1]
            res = max(res, dp[i])
        return res
