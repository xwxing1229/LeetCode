# https://leetcode.cn/problems/equal-row-and-column-pairs/

class Solution:
    def equalPairs(self, grid):
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: int
        """
        rows, cols = defaultdict(int), defaultdict(int)
        n = len(grid)
        for i in range(n):
            s = "-".join(map(str, grid[i]))
            rows[s] += 1
        for j in range(n):
            s = "-".join(map(str, [grid[i][j] for i in range(n)]))
            cols[s] += 1

        res = 0
        for s, cnt in rows.items():
            res += cnt * cols[s]
        return res