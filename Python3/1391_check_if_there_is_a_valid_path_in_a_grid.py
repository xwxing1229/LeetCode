# https://leetcode.cn/problems/check-if-there-is-a-valid-path-in-a-grid/

from collections import deque

class Solution:
    def hasValidPath(self, grid: list[list[int]]) -> bool:
        encode = {"left": [0,-1], "right": [0,1], "up": [-1,0], "down": [1,0]}
        forward = {
            1: {"left", "right"},
            2: {"up", "down"},
            3: {"left", "down"},
            4: {"right", "down"},
            5: {"left", "up"},
            6: {"right", "up"}
        }

        def IsForwardValid(i0, j0, i1, j1):
            street = grid[i0][j0]
            for direction in forward[street]:
                di, dj = encode[direction]
                if i0 + di == i1 and j0 + dj == j1:
                    return True
            return False

        m, n = len(grid), len(grid[0])
        q = deque()
        q.append((0,0))
        seen = [[False for _ in range(n)] for _ in range(m)]
        seen[0][0] = True
        while q:
            i0, j0 = q.popleft()
            if i0 == m - 1 and j0 == n - 1:
                return True
            for direction in forward[grid[i0][j0]]:
                di, dj = encode[direction]
                i, j = i0 + di, j0 + dj
                if 0 <= i < m \
                        and 0 <= j < n \
                        and IsForwardValid(i, j, i0, j0) \
                        and not seen[i][j]:
                    q.append((i,j))
                    seen[i][j] = True
        return False