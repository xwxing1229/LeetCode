# https://leetcode.cn/problems/triangle/

class Solution:
    def minimumTotal(self, triangle):
        """
        Inputs:
            triangle: list[list[int]]
        Outputs:
            res: int
        """
        
        # # Dynamic programming.
        # n = len(triangle)
        # dp = [0 for _ in range(n)]
        # dp[0] = triangle[0][0] # initialization
        
        # tmp = dp.copy() # an auxiliary list
        # for i in range(1,n):
        #     for j in range(1,i):
        #         dp[j] = min(tmp[j-1], tmp[j]) + triangle[i][j]
            
        #     dp[0] = dp[0] + triangle[i][0]
        #     dp[i] = tmp[i-1] + triangle[i][i]
        #     tmp = dp.copy()
        
        # res = min(dp)
        # return res

        n = len(triangle)
        if n == 1:
            return triangle[0][0]
        elif n == 2:
            return triangle[0][0] + min(triangle[1][0], triangle[1][1])

        dp = [0 for _ in range(n)]
        dp[0] = triangle[0][0] + triangle[1][0]
        dp[1] = triangle[0][0] + triangle[1][1]

        for row in range(2, n):
            last = dp[0]

            dp[0] = dp[0] + triangle[row][0]
            dp[row] = dp[row-1] + triangle[row][row]

            for i in range(1, row):
                tmp = min(last, dp[i]) + triangle[row][i]
                last = dp[i]
                dp[i] = tmp

        return min(dp)