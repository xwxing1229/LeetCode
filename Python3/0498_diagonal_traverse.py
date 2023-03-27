# https://leetcode.cn/problems/diagonal-traverse/

class Solution:
    def findDiagonalOrder(self, mat):
        """
        Inputs:
            mat: list[list[int]]
        Outputs:
            res: list[int]
        """
        res = []
        i, j = 0, 0
        up = True
        rows, cols = len(mat), len(mat[0])
        cnt, total = 0, rows * cols
        while cnt < total:
            res.append(mat[i][j])
            cnt += 1
            if up:
                i -= 1
                j += 1
                if i < 0:
                    if j < cols:
                        i += 1
                    else:
                        i += 2
                        j -= 1
                    up = False
                elif j >= cols:
                    i += 2
                    j -= 1
                    up = False
            else:
                i += 1
                j -= 1
                if j < 0:
                    if i < rows:
                        j += 1
                    else:
                        j += 2
                        i -= 1
                    up = True
                elif i >= rows:
                    j += 2
                    i -= 1
                    up = True
        return res