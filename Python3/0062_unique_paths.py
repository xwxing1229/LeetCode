# https://leetcode-cn.com/problems/unique-paths/

class Solution:
	def uniquePaths(self, m, n):
		"""
		Inputs:
			m: int
			n: int
		Outputs:
			res: int
		"""

		'''
		dp = [[1 for _ in range(n)] for _ in range(m)]
		for i in range(m):
			for j in range(n):
				dp[i][j] = dp[i-1][j] + dp[i][j-1]

		res = dp[m-1][n-1]
		return res
		'''

		# A better way that uses less memory space.
		dp = [1 for _ in range(n)]
		for _ in range(1,m):
			for j in range(1,n):
				dp[j] = dp[j-1] + dp[j]
				
		res = dp[-1]
		return res