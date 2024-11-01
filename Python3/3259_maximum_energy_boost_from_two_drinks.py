# https://leetcode.cn/problems/maximum-energy-boost-from-two-drinks/

class Solution:
    def maxEnergyBoost(self, energyDrinkA, energyDrinkB):
        """
        Inputs:
            energyDrinkA, energyDrinkB: list[int]
        Outputs:
            res: int
        """
        return max(self.f(energyDrinkA, energyDrinkB), self.f(energyDrinkB, energyDrinkA))

    def f(self, energyDrinkA, energyDrinkB):
        n = len(energyDrinkA)
        dp = [[0, 0] for _ in range(n+1)]
        for i in range(n):
            a, b = energyDrinkA[i], energyDrinkB[i]
            dp[i+1][0] = max(dp[i][0]+a, dp[i][1])
            dp[i+1][1] = max(dp[i][0], dp[i][1]+b)
        return max(dp[-1])