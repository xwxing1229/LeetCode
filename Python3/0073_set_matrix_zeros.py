# https://leetcode-cn.com/problems/set-matrix-zeroes/

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
        
        rows = len(matrix)
        cols = len(matrix[0])
        indices_row = set()
        indices_col = set()
        
        # Record indices.
        for row in range(rows):
            for col in range(cols):
                if matrix[row][col] == 0:
                    indices_row.add(row)
                    indices_col.add(col)
        
        # Set zeros.
        for row in indices_row:
            for col in range(cols):
                matrix[row][col] = 0
                
        for col in indices_col:
            for row in range(rows):
                matrix[row][col] = 0