# https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/

class Solution:
    def minScoreTriangulation(self, values):
    	"""
    	Inputs:
    		values: list[int]
    	Outputs:
    		res: int
    	"""
        n = len(values)
        dp = [[-1 for j in range(n)] for i in range(n)]
        for i in range(n-2, -1, -1):
            dp[i][i+1] = 0
            for j in range(i+2, n):
                for k in range(i+1, j):
                    tmp = dp[i][k] + values[i]*values[k]*values[j] + dp[k][j]
                    if dp[i][j] < 0:
                        dp[i][j] = tmp
                    else:
                        dp[i][j] = min(dp[i][j], tmp)
        return dp[0][n-1]