# https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/

class Solution:
    def maxProfit(self, prices):
        """
        Inputs:
            prices: list[int]
        Outputs:
            res: int
        """
        
        '''
        n = len(prices)
        dp = [0 for _ in range(n)]
        for i in range(1,n):
            # dp[i] indicates the maximum profit till now.
            dp[i] = dp[i-1] + max(0, prices[i]-prices[i-1])
        return dp[-1]
        '''

        res = 0
        for i in range(1, len(prices)):
            yesterday = prices[i-1]
            today = prices[i]
            if yesterday < today:
                res = res + today - yesterday
        return res