# https://leetcode.cn/problems/coin-change-ii/

class Solution:
    def change(self, amount, coins):
        """
        Inputs:
            amount: int
            coins: list[int]
        Outputs:
            res: int
        """
        dp = [0 for i in range(amount+1)]
        dp[0] = 1
        for coin in coins:
            for i in range(coin, amount+1):
                dp[i] += dp[i-coin]
        return dp[amount]