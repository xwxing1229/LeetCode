# https://leetcode.cn/problems/number-of-closed-islands/

class Solution:
    def closedIsland(self, grid):
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: int
        """
        m, n = len(grid), len(grid[0])
        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    q = deque()
                    q.append((i, j))
                    grid[i][j] = 1
                    closed = True
                    while q:
                        curi, curj = q.popleft()
                        if curi == 0 or curi == m-1 or curj == 0 or curj == n-1:
                            closed = False
                        for x, y in [(curi-1, curj), (curi+1, curj), (curi, curj-1), (curi, curj+1)]:
                            if x >= 0 and x < m and y >= 0 and y < n and grid[x][y] == 0:
                                q.append((x, y))
                                grid[x][y] = 1
                    if closed:
                        res += 1
        return res