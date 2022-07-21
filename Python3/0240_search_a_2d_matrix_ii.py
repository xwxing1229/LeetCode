# https://leetcode.cn/problems/search-a-2d-matrix-ii/

class Solution:
    def searchMatrix(self, matrix, target):
        """
        Inputs:
            matrix: list[list[int]]
            target: int
        Outputs:
            res: bool
        """
        row = 0
        col = len(matrix[0]) - 1
        while row < len(matrix) and col >= 0:
            val = matrix[row][col]
            if val == target:
                return True
            elif val < target:
                row = row + 1
            else:
                col = col - 1
        return False