# https://leetcode.cn/problems/first-completely-painted-row-or-column/

class Solution:
    def firstCompleteIndex(self, arr, mat):
        """
        Intputs:
            arr: list[int]
            mat: list[list[int]]
        Outputs:
            res: int
        """
        m, n = len(mat), len(mat[0])
        val_idx = dict()
        for i in range(m):
            for j in range(n):
                val_idx[mat[i][j]] = (i, j)
        paintrow = [0 for _ in range(m)]
        paintcol = [0 for _ in range(n)]
        for i, val in enumerate(arr):
            row, col = val_idx[val]
            paintrow[row] += 1
            paintcol[col] += 1
            if paintrow[row] == n or paintcol[col] == m:
                return i
        return -1