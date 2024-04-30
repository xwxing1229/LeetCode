# https://leetcode.cn/problems/sort-the-matrix-diagonally/

class Solution:
    def diagonalSort(self, mat):
        """
        Inputs:
            mat: list[list[int]]
        Outputs:
            res: list[list[int]]
        """
        m, n = len(mat), len(mat[0])
        for row in range(m-1, -1, -1):
            diag = []
            i, j = row, 0
            while i < m and j < n:
                diag.append(mat[i][j])
                i += 1
                j += 1
            diag.sort()

            i, j = row, 0
            for val in diag:
                mat[i][j] = val
                i += 1
                j += 1
                
        for col in range(1, n):
            diag = []
            i, j = 0, col
            while i < m and j < n:
                diag.append(mat[i][j])
                i += 1
                j += 1
            diag.sort()

            i, j = 0, col
            for val in diag:
                mat[i][j] = val
                i += 1
                j += 1
        return mat