# https://leetcode-cn.com/problems/rotate-image/
class Solution:
    def rotate(self, matrix):
        """
        Inputs:
            matrix: list[list[int]]
        """

        """
        Do not return anything, modify matrix in-place instead.
        """

        n = len(matrix)
        t = n // 2
        for i in range(t):
            for j in range(i, n - 1 - i):
                matrix[i][j], matrix[j][n-1-i] = matrix[j][n-1-i], matrix[i][j]
                matrix[i][j], matrix[n-1-i][n-1-j] = matrix[n-1-i][n-1-j], matrix[i][j]
                matrix[i][j], matrix[n-1-j][i] = matrix[n-1-j][i], matrix[i][j]