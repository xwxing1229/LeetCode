# https://leetcode.cn/problems/spiral-matrix-ii/

class Solution:
    def generateMatrix(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: list[list[int]]
        """

        res = [[0 for col in range(n)] for row in range(n)]
        return self.generateCircle(n, 0, 1, res)

    def generateCircle(self, n, start_row, num, matrix):
        if start_row >= (n+1) // 2:
            return matrix
        end_row = n - 1 - start_row
        if start_row == end_row:
            matrix[start_row][start_row] = num
            return matrix

        for col in range(start_row, end_row+1):
            matrix[start_row][col] = num
            num = num + 1
        for row in range(start_row+1, end_row):
            matrix[row][end_row] = num
            num = num + 1
        for col in range(end_row, start_row-1, -1):
            matrix[end_row][col] = num
            num = num + 1
        for row in range(end_row-1, start_row, -1):
            matrix[row][start_row] = num
            num = num + 1
        return self.generateCircle(n, start_row+1, num, matrix)