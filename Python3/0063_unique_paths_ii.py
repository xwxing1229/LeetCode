# https://leetcode-cn.com/problems/unique-paths-ii/

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        Inputs:
            obstacleGrid: list[list[int]]
        Outputs:
            res: int
        """
        
        '''
        if obstacleGrid[-1][-1] == 1:
            return 0
        
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        dp = [[1 for _ in range(n)] for _ in range(m)]
        
        # Initialization.
        for i in range(m):
            if obstacleGrid[i][0] == 1:
                while i < m:
                    dp[i][0] = 0
                    i = i + 1
                break
        for j in range(n):
            if obstacleGrid[0][j] == 1:
                dp[0][j:] = [0] * (n-j)
                break
        
        # Dynamic programming.
        for i in range(1,m):
            for j in range(1,n):
                if obstacleGrid[i][j] == 1:
                    dp[i][j] = 0
                else:
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[-1][-1]
        '''
        
        # A better way that uses less memory space.
        if obstacleGrid[-1][-1] == 1 or obstacleGrid[0][0] == 1:
            return 0

        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        dp = [0 for _ in range(n)]
        # Initialization.
        for j in range(n):
            if obstacleGrid[0][j] != 1:
                dp[j] = 1
            else:
                break
        
        # Dynamic programming.
        for i in range(1,m):
            if obstacleGrid[i][0] == 1 or dp[0] == 0:
                dp[0] = 0
            for j in range(1,n):
                if obstacleGrid[i][j] == 1:
                    dp[j] = 0
                else:
                    dp[j] = dp[j-1] + dp[j]
                # print(dp)
                
        res = dp[-1]
        return res