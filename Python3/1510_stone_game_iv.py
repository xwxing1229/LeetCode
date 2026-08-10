# https://leetcode.cn/problems/stone-game-iv/

from math import sqrt

class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        dp = [False for _ in range(n+1)]
        for i in range(1, n+1):
            for x in range(1, int(sqrt(i))+1):
                if dp[i - x * x] == False:
                    dp[i] = True
                    break
        return dp[-1]