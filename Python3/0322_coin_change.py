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

        dp = [0 for _ in range(amount+1)]
        for i in range(1, amount+1):
            tmp = amount + 1
            for coin in coins:
                rem = i - coin
                if rem == 0:
                    tmp = 0
                elif (rem > 0) and (dp[rem] > 0):
                    tmp = min(tmp, dp[rem])

                if tmp == amount + 1:
                    dp[i] = -1
                else:
                    dp[i] = tmp + 1
        return dp[amount]