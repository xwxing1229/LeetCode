# https://leetcode-cn.com/problems/triangle/

class Solution:
    def minimumTotal(self, triangle):
        """
        Inputs:
            triangle: list[list[int]]
        Outputs:
            res: int
        """
        
        # Dynamic programming.
        n = len(triangle)
        dp = [0 for _ in range(n)]
        dp[0] = triangle[0][0] # initialization
        
        tmp = dp.copy() # an auxiliary list
        for i in range(1,n):
            for j in range(1,i):
                dp[j] = min(tmp[j-1], tmp[j]) + triangle[i][j]
            
            dp[0] = dp[0] + triangle[i][0]
            dp[i] = tmp[i-1] + triangle[i][i]
            tmp = dp.copy()
        
        res = min(dp)
        return res