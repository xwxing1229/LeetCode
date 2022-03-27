# # https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/

class Solution:
    def maxProfit(self, prices):
        """
        Inputs:
            prices: list[int]
        Outputs:
            res: int
        """
        
        res = 0
        min_price = prices[0]
        for price in prices:
            # Find the minimum price till now.
            min_price = min(min_price, price)
            # Find the maximum profit till now.
            res = max(res, price-min_price)
        return res