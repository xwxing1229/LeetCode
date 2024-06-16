# https://leetcode.cn/problems/rotting-oranges/

class Solution:
    def orangesRotting(self, grid):
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: int
        """
        from collections import deque
        
        m, n = len(grid), len(grid[0])
        rot, orange = 0, 0
        visited = [[0 for _ in range(n)] for _ in range(m)]
        q = deque()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    q.append((i,j))
                    rot += 1
                    visited[i][j] = 1
                    orange += 1
                elif grid[i][j] == 1:
                    orange += 1
        if rot == orange:
            return 0
        
        res = -1
        dirs = [[-1,0], [1,0], [0,-1], [0,1]]
        while len(q) > 0:
            res += 1
            num = len(q)
            for _ in range(num):
                cur = q.popleft()
                for d in dirs:
                    i, j = cur[0]+d[0], cur[1]+d[1]
                    if i < 0 or i >= m or j < 0 or j >= n:
                        continue
                    if grid[i][j] == 0 or visited[i][j]:
                        continue
                    q.append((i,j))
                    rot += 1
                    visited[i][j] = 1
        if rot == orange:
            return res
        else:
            return -1