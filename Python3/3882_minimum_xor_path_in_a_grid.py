# https://leetcode.cn/problems/minimum-xor-path-in-a-grid/

class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        self.res = float("inf")
        seen = set()

        def dfs(i: int, j: int, xor: int) -> None:
            if self.res == 0:
                return
            if i < 0 or j < 0 or (i, j, xor) in seen:
                return
            seen.add((i, j, xor))
            xor ^= grid[i][j]
            if i == 0 and j == 0:
                self.res = min(self.res, xor)
                return
            dfs(i-1, j, xor)
            dfs(i, j-1, xor)

        dfs(len(grid)-1, len(grid[0])-1, 0)
        return self.res