# https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution:
    def maxProfit(self, prices):
        """
        Inputs:
            prices: list[int]
        Outputs:
            res: int
        """
        
        # Five situations:
        # 1. 0 stock is bought until day i.
        # 2. 1 stock is bought until day i.
        # 3. 1 stock is sold until day i.
        # 4. 2 stocks are bought until day i.
        # 5. 2 stocks are sold until day i.
        
        # buy1:  maximum profit until day i
        #        with one stock brought
        # sell1: maximum profit until day i
        #        with one stock sold
        # buy2:  maximum profit until day i
        #        with two stocks brought
        # sell2: maximum profit until day i
        #        with two stocks sold
        
        buy1 = -prices[0]
        sell1 = 0
        buy2 = -prices[0]
        sell2 = 0
        
        for i in range(1, len(prices)):
            buy1 = max(buy1, -prices[i])
            sell1 = max(sell1, buy1 + prices[i])
            buy2 = max(buy2, sell1 - prices[i])
            sell2 = max(sell2, buy2 + prices[i])
            
        return sell2