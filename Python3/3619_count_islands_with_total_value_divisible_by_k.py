# https://leetcode.cn/problems/count-islands-with-total-value-divisible-by-k/

from collections import deque

class Solution:
    def countIslands(self, grid: list[list[int]], k: int) -> int:
        res = 0
        m, n = len(grid), len(grid[0])
        dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        seen = [[False for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0 or seen[i][j]:
                    continue
                q = deque()
                q.append((i, j))
                seen[i][j] = True
                s = grid[i][j]
                while q:
                    i0, j0 = q.popleft()
                    for di, dj in dirs:
                        ni, nj = i0 + di, j0 + dj
                        if ni >= 0 and ni < m and nj >= 0 and nj < n \
                            and grid[ni][nj] != 0 and not seen[ni][nj]:
                            q.append((ni, nj))
                            seen[ni][nj] = True
                            s += grid[ni][nj]
                res += (s % k == 0)
        return res