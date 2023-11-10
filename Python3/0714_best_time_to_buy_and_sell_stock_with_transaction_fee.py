# https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution:
    def maxProfit(self, prices, fee):
        """
        Inputs:
            prices: list[int]
            fee: int
        Outputs:
            res: int
        """
        # dp0: maximum profit with 0 stock held
        # dp1: maximum profit with 1 stock held
        dp0, dp1 = 0, -prices[0]
        dp0_pre, dp1_pre = dp0, dp1
        for i in range(1, len(prices)):
            cur = prices[i]
            dp0 = max(dp0_pre, dp1_pre + cur - fee)
            dp1 = max(dp1_pre, dp0_pre - cur)
            dp0_pre = dp0
            dp1_pre = dp1
        return dp0