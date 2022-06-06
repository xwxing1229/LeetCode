# https://leetcode.cn/problems/spiral-matrix/

class Solution:
    def spiralOrder(self, matrix):
        """
        Inputs:
            matrix: list[list[int]]
        Outputs:
            res: list[int]
        """

        return self.spiralSub(matrix, [])

    def spiralSub(self, matrix, spiral):
        rows = len(matrix)
        cols = len(matrix[0])

        if rows == 1:
            spiral = spiral + matrix[0]
            return spiral
        elif cols == 1:
            for row in range(rows):
                spiral.append(matrix[row][0])
            return spiral
        else:
            spiral = spiral + matrix[0]
            for row in range(1, rows-1):
                spiral.append(matrix[row][cols-1])
            for col in range(cols-1, -1, -1):
                spiral.append(matrix[rows-1][col])
            for row in range(rows-2, 0, -1):
                spiral.append(matrix[row][0])

            if (rows == 2) or (cols == 2):
                return spiral
            else:
                tmp = matrix.copy()
                tmp.pop()
                tmp.pop(0)
                for row in range(len(tmp)):
                    tmp[row].pop()
                    tmp[row].pop(0)
                return self.spiralSub(tmp, spiral)