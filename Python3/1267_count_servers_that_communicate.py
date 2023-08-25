# https://leetcode.cn/problems/count-servers-that-communicate/

class Solution:
    def countServers(self, grid):
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: int
        """
        m, n = len(grid), len(grid[0])
        s = set()
        for i in range(m):
            j = 0
            while j < n and grid[i][j] == 0:
                j += 1
            k = i * n + j
            j += 1
            while j < n:
                if grid[i][j] == 1:
                    s.add(k)
                    s.add(i * n + j)
                j += 1
        for j in range(n):
            i = 0
            while i < m and grid[i][j] == 0:
                i += 1
            k = i * n + j
            i += 1
            while i < m:
                if grid[i][j] == 1:
                    s.add(k)
                    s.add(i * n + j)
                i += 1
        return len(s)