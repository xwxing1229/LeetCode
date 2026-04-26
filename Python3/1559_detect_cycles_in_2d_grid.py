# https://leetcode.cn/problems/detect-cycles-in-2d-grid/

class Solution:
    def containsCycle(self, grid: list[list[str]]) -> bool:
        m, n = len(grid), len(grid[0])
        visited = [[False for _ in range(n)] for _ in range(m)]
        directions = [[0,1], [0,-1], [1,0], [-1,0]]

        def dfs(x, y, x_prev, y_prev):
            visited[x][y] = True
            for dx, dy in directions:
                x_next, y_next = x + dx, y + dy
                if x_next < 0 or x_next >= m or y_next < 0 or y_next >= n or grid[x_next][y_next] != grid[x][y]:
                    continue
                if visited[x_next][y_next]:
                    if x_next != x_prev or y_next != y_prev:
                        return True
                    continue
                if dfs(x_next, y_next, x, y):
                    return True
            return False
        
        for i in range(m):
            for j in range(n):
                if not visited[i][j] and dfs(i, j, -1, -1):
                    return True
        return False