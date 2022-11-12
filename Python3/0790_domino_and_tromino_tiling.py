# https://leetcode.cn/problems/domino-and-tromino-tiling/

class Solution:
    def numTilings(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """

        # dp[i][0]: in the ith column, no tile
        # dp[i][1]: in the ith column, only 1 tile in the 1st row
        # dp[i][2]: in the ith column, only 1 tile in the 2nd row
        # dp[i][3]: in the ith column, 2 tiles in both rows
        if n == 1:
            return 1
        elif n == 2:
            return 2
            
        dp = [[1,1,1,2] for _ in range(n)]
        for i in range(2, n):
            dp[i][0] = dp[i-1][3]
            dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % 1000000007
            dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % 1000000007
            dp[i][3] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2] + dp[i-1][3]) % 1000000007
        return dp[n-1][3]