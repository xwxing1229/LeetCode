# https://leetcode.cn/problems/matrix-diagonal-sum/

class Solution:
    def diagonalSum(self, mat):
        """
        Inputs:
            mat: list[list[int]]
        Outputs:
            res: int
        """
        res = 0
        n = len(mat)
        for i in range(n):
            res += (mat[i][i] + mat[i][n-1-i])
        if n % 2 == 1:
            res -= mat[n//2][n//2]
        return res