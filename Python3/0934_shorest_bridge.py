# https://leetcode.cn/problems/shortest-bridge/

class Solution:
    def shortestBridge(self, grid):
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: int
        """

        self.boundary = []
        self.findIsland(grid)

        res = 0
        dirs = [[1,0], [-1,0], [0,1], [0,-1]]
        rows, cols = len(grid), len(grid[0])
        while self.boundary:
            res += 1
            k = len(self.boundary)
            while k > 0:
                pos = self.boundary.pop(0)
                k -= 1

                for d in dirs:
                    i, j = pos[0] + d[0], pos[1] + d[1]
                    if (i < 0) or (i >= rows) or (j < 0) or (j >= cols):
                        continue
                    if grid[i][j] == 0:
                        grid[i][j] = 2
                        self.boundary.append([i,j])
                    elif grid[i][j] == 1:
                        return res
        return 0

    def findIsland(self, grid):
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    self.dfs(grid, i, j)
                    return

    def dfs(self, grid, i, j):
        if (i < 0) or (i >= len(grid)) or (j < 0) or (j >= len(grid[0])):
            return

        if grid[i][j] == 0:
            grid[i][j] = 2
            self.boundary.append([i,j])
        elif grid[i][j] == 1:
            grid[i][j] = 2
            self.dfs(grid, i+1, j)
            self.dfs(grid, i-1, j)
            self.dfs(grid, i, j+1)
            self.dfs(grid, i, j-1)
