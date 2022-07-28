# https://leetcode.cn/problems/perfect-squares/

class Solution:
    def numSquares(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """
        dp = [0 for _ in range(n+1)]
        dp[1] = 1
        for i in range(2, n+1):
            tmp = dp[i-1]
            for j in range(1, int(math.sqrt(i))+1):
                tmp = min(tmp, dp[i-j*j])
            dp[i] = 1 + tmp
        return dp[n]