# https://leetcode.cn/problems/check-if-there-is-a-valid-parentheses-string-path/

class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        m, n = len(grid), len(grid[0])
        if (m + n) % 2 == 0 or grid[0][0] == ")" or grid[-1][-1] == "(":
            return False

        visit = [[[False for _ in range((m+n+1)//2)] for _ in range(n)] for _ in range(m)]

        def dfs(i: int, j: int, c: int) -> bool:
            # Cannot make c = 0 even though there are all ")" on the remaining path.
            if c > m - i + n - j - 1:
                return False
            # End point.
            if i == m - 1 and j == n - 1:
                return c == 1
            # Already visited.
            if visit[i][j][c]:
                return False
            visit[i][j][c] = True

            c += 1 if grid[i][j] == "(" else -1
            if c < 0:
                return False
            return (i < m - 1 and dfs(i+1, j, c)) \
                or (j < n - 1 and dfs(i, j+1, c))

        return dfs(0, 0, 0)