# https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/

class Solution:
    def numRollsToTarget(self, n, k, target):
        """
        Inputs:
            n, k, target: int
        Outputs:
            res: int
        """
        mod = 1000000007
        dp = [[0 for j in range(target+1)] for i in range(n)]
        for j in range(1, min(target,k)+1):
            dp[0][j] = 1
        for i in range(1, n):
            for j in range(1, target+1):
                for roll in range(1, min(j, k)+1):
                    dp[i][j] = (dp[i][j] + dp[i-1][j-roll]) % mod
        return dp[-1][-1]