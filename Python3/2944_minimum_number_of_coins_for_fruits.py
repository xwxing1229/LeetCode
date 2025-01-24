# https://leetcode.cn/problems/minimum-number-of-coins-for-fruits/

class Solution:
    def minimumCoins(self, prices):
        """
        Inputs:
            prices: list[int]
        Outputs:
            res: int
        """
        # dp[i][0]: minimum number of coins until the ith fruit without buying the ith fruit.
        # dp[i][1]: minimum number of coins until the ith fruit with buying the ith fruit.
        n = len(prices)
        dp = [[prices[0], prices[0]] for _ in range(n+1)]
        for i in range(2, n+1):
            dp[i][0] = dp[i-1][1]
            for j in range((i+1)//2, i):
                dp[i][0] = min(dp[i][0], dp[j][1])
            dp[i][1] = min(dp[i-1]) + prices[i-1]
        return min(dp[-1])