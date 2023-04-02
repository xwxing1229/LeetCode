# https://leetcode.cn/problems/fibonacci-number/

class Solution:
    def fib(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """
        dp = [0 for i in range(n+2)]
        dp[1] = 1
        for i in range(2, n+1):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n]