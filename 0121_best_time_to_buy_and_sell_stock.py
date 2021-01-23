# https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/

class Solution:
    def maxProfit(self, prices):
        """
        Inputs:
            prices: list[int]
        Outputs:
            res: int
        """
        
        res = 0
        buy = prices[0]
        for price in prices:
            res = max(price-buy, res)
            buy = min(price, buy)
        return res