# https://leetcode.cn/problems/coin-change/

class Solution:
    def coinChange(self, coins, amount):
        """
        Inputs:
            coins: list[int]
            amount: int
        Outputs:
            res: int
        """

        dp = [amount+1 for _ in range(amount+1)]
        dp[0] = 0
        for i in range(1, amount+1):
            for coin in coins:
                if coin <= i and dp[i-coin] + 1 < dp[i]:
                    dp[i] = dp[i-coin] + 1
        return dp[amount] if dp[amount] != amount+1 else -1