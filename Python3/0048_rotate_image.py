# https://leetcode.cn/problems/rotate-image/

class Solution:
    def rotate(self, matrix: list[list[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # Split the matrix into four regions, excluding the center.
        n = len(matrix)
        row_max, col_max = n//2-1, n//2+n%2-1
        for i in range(row_max+1):
            for j in range(col_max+1):
                tl = matrix[i][j]
                tr = matrix[j][n-1-i]
                br = matrix[n-1-i][n-1-j]
                bl = matrix[n-1-j][i]
                matrix[i][j] = bl
                matrix[j][n-1-i] = tl
                matrix[n-1-i][n-1-j] = tr
                matrix[n-1-j][i] = br