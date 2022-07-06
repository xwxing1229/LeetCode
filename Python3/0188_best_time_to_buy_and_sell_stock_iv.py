# https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/

class Solution:
    def maxProfit(self, k, prices):
        """
        Inputs:
            k: int
            prices: list[int]
        Outputs:
            res: int
        """
        
        '''
        Dynamic programming.

        If a stock is bought, then we say a transaction
        is finished.
        
        dp[i][j][m]: the maximum profit at the ith day,
        with j (0 / 1) stock in stock and m transactions
        finished.
        
        n = len(prices)
        if n < 2:
            return 0
        
        # One transaction takes two days.
        k = min(k, n//2)
        
        dp = [[[0 for _ in range(k+1)] \
                for _ in range(2)] \
                for _ in range(n)]
        
        # Initialization.
        for m in range(k+1):
            dp[0][0][m] = 0
            dp[0][1][m] = -prices[0]
            
        for m in range(1, k+1):
            for i in range(1, n):
                dp[i][0][m] = max(dp[i-1][0][m],
                  dp[i-1][1][m] + prices[i])
                
                dp[i][1][m] = max(dp[i-1][1][m],
                  dp[i-1][0][m-1] - prices[i])
                
        return dp[n-1][0][k]

        '''

        # Based on #0123.
        n = len(prices)
        k = min(k, n//2)
        if k == 0:
            return 0

        buy_sell = [0 for _ in range(2*k)]
        for i in range(k):
            buy_sell[2*i] = -prices[0]
        for price in prices:
            buy_sell[0] = max(buy_sell[0], -price)
            for i in range(1, 2*k):
                if i % 2 == 0:
                    buy_sell[i] = max(buy_sell[i], buy_sell[i-1] - price)
                else:
                    buy_sell[i] = max(buy_sell[i], price + buy_sell[i-1])
        return buy_sell[2*k-1]