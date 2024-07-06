# https://leetcode.cn/problems/modify-the-matrix/

class Solution:
    def modifiedMatrix(self, matrix):
        """
        Inputs:
            matrix: list[list[int]]
        Outputs:
            res: list[list[int]]
        """
        m, n = len(matrix), len(matrix[0])
        max_col = [0 for _ in range(n)]
        replace = []
        for j in range(n):
            max_val = matrix[0][j]
            for i in range(m):
                val = matrix[i][j]
                max_val = max(max_val, val)
                if val == -1:
                    replace.append([i,j])
            max_col[j] = max_val
            
        for i, j in replace:
            matrix[i][j] = max_col[j]
        return matrix