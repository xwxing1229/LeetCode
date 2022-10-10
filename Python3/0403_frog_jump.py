# https://leetcode.cn/problems/frog-jump/

class Solution:
    def canCross(self, stones):
        """
        Inputs:
            stones: list[int]
        Outputs:
            res: bool
        """
        
        # dp[i][k] = 1: can reach the ith stone with a jump of k units from a previous stone
        # dp[i][k] = 0: cannot reach the ith stone with a jump of k units from a previous stone
        n = len(stones)
        dp = [[False for j in range(n+1)] for i in range(n)]
        dp[0][0] = True
        for i in range(1, n):
            for j in range(i-1, -1, -1):
                k = stones[i] - stones[j]
                if k > j+1:
                    continue
                if dp[j][k-1] or dp[j][k] or dp[j][k+1]:
                    dp[i][k] = True
                    if i == n-1:
                        return True
        return False