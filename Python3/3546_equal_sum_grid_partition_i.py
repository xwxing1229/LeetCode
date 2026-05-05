# https://leetcode.cn/problems/equal-sum-grid-partition-i/

class Solution:
    def canPartitionGrid(self, grid: list[list[int]]) -> bool:
        def canPartition(grid):
            m, n = len(grid), len(grid[0])
            suffix = [0 for _ in range(m)]
            tmp = 0
            for i in range(m-1, 0, -1):
                for j in range(n-1, -1, -1):
                    tmp += grid[i][j]
                suffix[i-1] = tmp
            
            prefix = 0
            for i in range(m):
                for j in range(n):
                    prefix += grid[i][j]
                if prefix == suffix[i]:
                    return True
            return False
        
        m, n = len(grid), len(grid[0])
        grid_T = [[0 for _ in range(m)] for _ in range(n)]
        for i in range(m):
            for j in range(n):
                grid_T[j][i] = grid[i][j]
        
        return canPartition(grid) or canPartition(grid_T)