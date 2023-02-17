# https://leetcode.cn/problems/largest-1-bordered-square/

class Solution:
    def largest1BorderedSquare(self, grid):
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: int
        """
        rows, cols = len(grid), len(grid[0])
        # down[i][j]: number of consecutive 1 downwards at (i,j)
        # right[i][j]: number of consecutive 1 rightward at (i,j)
        down = [[0 for j in range(cols)] for i in range(rows)]
        right = [[0 for j in range(cols)] for i in range(rows)]
        for i in range(rows-1, -1, -1):
            for j in range(cols-1, -1, -1):
                if grid[i][j] == 1:
                    if i + 1 < rows:
                        down[i][j] = down[i+1][j] + 1
                    else:
                        down[i][j] = 1
                    if j + 1 < cols:
                        right[i][j] = right[i][j+1] + 1
                    else:
                        right[i][j] = 1

        for k in range(min(rows, cols), 0, -1):
            for i in range(rows - k + 1):
                for j in range(cols - k + 1):
                    if down[i][j] >= k and right[i][j] >= k and down[i][j+k-1] >= k and right[i+k-1][j] >= k:
                        return k * k
        return 0