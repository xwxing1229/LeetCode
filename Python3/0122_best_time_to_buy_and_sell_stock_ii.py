# https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution:
    def maxProfit(self, prices):
        """
        Inputs:
            prices: list[int]
        Outputs:
            res: int
        """
        
        '''
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
        '''
        
        n = len(prices)
        dp = [0 for _ in range(n)]
        for i in range(1,n):
            # dp[i] indicates the maximum profit till now.
            dp[i] = dp[i-1] + max(0, prices[i]-prices[i-1])
        return dp[-1]
