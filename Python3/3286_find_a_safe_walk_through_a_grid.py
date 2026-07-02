# https://leetcode.cn/problems/find-a-safe-walk-through-a-grid/

import heapq

class Solution:
    def findSafeWalk(self, grid: list[list[int]], health: int) -> bool:
        direction = [[0,1], [0,-1], [1,0], [-1,0]]
        m, n = len(grid), len(grid[0])
        hq = [(-health+grid[0][0], 0, 0)]
        seen = [[False for _ in range(n)] for _ in range(m)]
        seen[0][0] = True
        while hq:
            curr, i0, j0 = heapq.heappop(hq)
            if i0 == m-1 and j0 == n-1:
                return True
            for di, dj in direction:
                i, j = i0 + di, j0 + dj
                if 0 <= i < m and 0 <= j < n \
                    and not seen[i][j] \
                    and -curr - grid[i][j] > 0:
                    heapq.heappush(hq, (curr + grid[i][j], i, j))
                    seen[i][j] = True
        return False