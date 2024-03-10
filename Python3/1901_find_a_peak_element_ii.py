# https://leetcode.cn/problems/find-a-peak-element-ii/

class Solution:
    def findPeakGrid(self, mat):
        """
        Inputs:
            mat: list[list[int]]
        Outputs:
            res: list[int]
        """
        rows, cols = len(mat), len(mat[0])
        low, high = 0, rows-1
        while low <= high:
            mid = (low + high) // 2
            j = mat[mid].index(max(mat[mid]))
            if mid >= 1 and mat[mid][j] < mat[mid-1][j]:
                high = mid - 1
                continue
            if mid < rows-1 and mat[mid][j] < mat[mid+1][j]:
                low = mid + 1
                continue
            return [mid, j]
        return [-1, -1]