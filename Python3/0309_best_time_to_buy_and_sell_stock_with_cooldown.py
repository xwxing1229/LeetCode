# https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution:
    def maxProfit(self, prices):
        """
        Inputs:
            prices: list[int]
        Outputs:
            res: int
        """
        dp0 = -prices[0] # a stock is held
        dp1 = 0 # no stock is held, in freezing period
        dp2 = 0 # no stock is held, not in freezing period
        for i in range(1, len(prices)):
            dp0_pre = dp0
            dp1_pre = dp1
            dp2_pre = dp2

            dp0 = max(dp0_pre, dp2_pre - prices[i])
            dp1 = dp0_pre + prices[i]
            dp2 = max(dp1_pre, dp2_pre)
        return max(dp1, dp2)