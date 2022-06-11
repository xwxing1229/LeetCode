# https://leetcode.cn/problems/set-matrix-zeroes/

class Solution:
    def setZeros(self, matrix):
        """
        Inputs:
            matrix: list[list[int]]
        Outputs:
            None
        """
        
        """
        Do not return anything, modify matrix in-place instead.
        """

        set_first_row = False
        set_first_col = False
        rows = len(matrix)
        cols = len(matrix[0])

        for col in range(cols):
            if matrix[0][col] == 0:
                set_first_row = True
                break
        for row in range(rows):
            if matrix[row][0] == 0:
                set_first_col = True
                break

        for row in range(1, rows):
            for col in range(1, cols):
                if matrix[row][col] == 0:
                    matrix[0][col] = 0
                    matrix[row][0] = 0
        
        for row in range(1, rows):
            for col in range(1, cols):
                if (matrix[0][col] == 0) or (matrix[row][0] == 0):
                    matrix[row][col] = 0
        if set_first_row:
            for col in range(cols):
                matrix[0][col] = 0
        if set_first_col:
            for row in range(rows):
                matrix[row][0] = 0