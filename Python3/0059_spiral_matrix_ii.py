# https://leetcode.cn/problems/spiral-matrix-ii/

class Solution:
    def generateMatrix(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: list[list[int]]
        """
        res = [[0 for _ in range(n)] for _ in range(n)]
        dirs = [[0,1], [1,0], [0,-1], [-1,0]]
        dir_id = 0
        dir = dirs[dir_id]
        row, top, bottom = 0, 0, n-1
        col, left, right = 0, 0, n-1
        for val in range(1, n*n+1):
            res[row][col] = val

            i, j = row + dir[0], col + dir[1]
            if (i >= top and i <= bottom and j >= left and j <= right):
                row, col = i, j
                continue

            dir_id = (dir_id + 1) % 4
            dir = dirs[dir_id]
            row += dir[0]
            col += dir[1]
            if i < top:
                left += 1
            elif i > bottom:
                right -= 1
            elif j < left:
                bottom -= 1
            else:
                top += 1
        return res