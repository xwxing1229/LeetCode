# https://leetcode.cn/problems/find-valid-matrix-given-row-and-column-sums/
        
class Solution:
    def restoreMatrix(self, rowSum, colSum):
        """
        Inputs:
            rowSum, colSum: list[int]
        Outputs:
            res: list[list[int]]
        """
        rows, cols = len(rowSum), len(colSum)
        res = [[0 for j in range(cols)] for i in range(rows)]
        i, j = 0, 0
        while i < rows and j < cols:
            val = min(rowSum[i], colSum[j])
            res[i][j] = val
            rowSum[i] -= val
            colSum[j] -= val
            if rowSum[i] == 0:
                i += 1
            if colSum[j] == 0:
                j += 1
        return res