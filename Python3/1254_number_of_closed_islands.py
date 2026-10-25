# https://leetcode.cn/problems/number-of-closed-islands/

from collections import deque

class Solution:
    def closedIsland(self, grid: list[list[int]]) -> int:
        res = 0
        m, n = len(grid), len(grid[0])
        seen = [[False for _ in range(n)] for _ in range(m)]
        dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1 or seen[i][j]:
                    continue
                q = deque()
                q.append((i, j))
                seen[i][j] = True
                closed = True
                while q:
                    i0, j0 = q.popleft()
                    if i0 == 0 or i0 == m-1 or j0 == 0 or j0 == n-1:
                        closed = False
                    for di, dj in dirs:
                        ni, nj = i0 + di, j0 + dj
                        if ni >= 0 and ni < m and nj >= 0 and nj < n \
                            and grid[ni][nj] == 0 and not seen[ni][nj]:
                            q.append((ni, nj))
                            seen[ni][nj] = True
                res += closed
        return res