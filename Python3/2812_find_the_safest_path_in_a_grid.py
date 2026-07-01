# https://leetcode.cn/problems/find-the-safest-path-in-a-grid/

from collections import deque

class Solution:
    def maximumSafenessFactor(self, grid: list[list[int]]) -> int:
        n = len(grid)
        if grid[0][0] == 1 or grid[-1][-1] == 1:
            return 0
        distance = [[-1 for _ in range(n)] for _ in range(n)]
        direction = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        q = deque()
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    distance[i][j] = 0
                    q.append((i, j))
        while q:
            i0, j0 = q.popleft()
            for di, dj in direction:
                i, j = i0 + di, j0 + dj
                if 0 <= i < n and 0 <= j < n and distance[i][j] == -1:
                    distance[i][j] = distance[i0][j0] + 1
                    q.append((i, j))
        
        def _check(dist: int) -> bool:
            q = deque()
            q.append((0, 0))
            visit = [[0 for _ in range(n)] for _ in range(n)]
            visit[0][0] = True
            while q:
                i0, j0 = q.popleft()
                if i0 == n-1 and j0 == n-1:
                    return True
                for di, dj in direction:
                    i, j = i0 + di, j0 + dj
                    if 0 <= i < n and 0 <= j < n \
                        and not visit[i][j] \
                        and distance[i][j] >= dist:
                        q.append((i, j))
                        visit[i][j] = 1
            return False

        res = 0
        left, right = 0, min(distance[0][0], distance[n-1][n-1])
        while left <= right:
            mid = (left + right) // 2
            if _check(mid):
                res = mid
                left = mid + 1
            else:
                right = mid - 1
        return res