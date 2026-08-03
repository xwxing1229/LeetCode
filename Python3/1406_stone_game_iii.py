# https://leetcode.cn/problems/stone-game-iii/

import math

class Solution:
    def stoneGameIII(self, stoneValue: list[int]) -> str:
        n = len(stoneValue)
        dp = [-math.inf for _ in range(n)] + [0]
        for i in range(n-1, -1, -1):
            s = 0
            for j in range(i, min(i+3, n)):
                s += stoneValue[j]
                dp[i] = max(dp[i], s - dp[j+1])
        if dp[0] > 0:
            return "Alice"
        elif dp[0] == 0:
            return "Tie"
        return "Bob"