# https://leetcode.cn/problems/search-a-2d-matrix/

class Solution:
    def searchMatrix(self, matrix, target):
        """
        Inputs:
            matrix: list[list[int]]
            target: int
        Outputs:
            res: bool
        """

        rows = len(matrix)
        cols = len(matrix[0])

        left = 0
        right = rows - 1
        row = 0
        while left <= right:
            mid = left + (right - left) // 2
            val = matrix[mid][0]
            if val <= target:
                left = mid + 1
                row = mid
            else:
                right = mid - 1

        left = 0
        right = cols - 1
        while left <= right:
            mid = left + (right - left) // 2
            val = matrix[row][mid]
            if val < target:
                left = mid + 1
            elif val > target:
                right = mid - 1
            else:
                return True
        return False