# https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution:
    def maxProfit(self, prices):
        """
        Inputs:
            prices: list[int]
        Outputs:
            sum(res): int
        """
        
        res = []
        profit = 0
        buy = prices[0]
        prices.append(0)
        for price in prices:
            if price - buy < profit:
                res.append(profit)
                buy = price
                profit = 0
            else:
                profit = price - buy
        return sum(res)