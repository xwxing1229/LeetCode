# https://leetcode.cn/problems/right-triangles/

class Solution:
    def numberOfRightTriangles(self, grid):
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: int
        """
        rows, cols = len(grid), len(grid[0])
        cnts = [[[0, 0, 0, 0] for _ in range(cols)] for _ in range(rows)]
        for i in range(rows):
            # Left.
            cnt = grid[i][0]
            for j in range(1, cols):
                cnts[i][j][0] = cnt
                cnt += grid[i][j]
            # Right.
            cnt = grid[i][cols-1]
            for j in range(cols-2, -1, -1):
                cnts[i][j][1] = cnt
                cnt += grid[i][j]
        
        for j in range(cols):
            # Above.
            cnt = grid[0][j]
            for i in range(1, rows):
                cnts[i][j][2] = cnt
                cnt += grid[i][j]
            # Below.
            cnt = grid[rows-1][j]
            for i in range(rows-2, -1, -1):
                cnts[i][j][3] = cnt
                cnt += grid[i][j]
        
        res = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    res += (cnts[i][j][0] + cnts[i][j][1]) * (cnts[i][j][2] + cnts[i][j][3])
        return res
