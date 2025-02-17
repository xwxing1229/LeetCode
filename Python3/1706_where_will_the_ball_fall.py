# https://leetcode.cn/problems/where-will-the-ball-fall/

class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: list[int]
        """
        def fall(start):
            j = start
            for i in range(m):
                if grid[i][j] >0 and (j+1<n and grid[i][j+1] >0):
                    j += 1
                elif grid[i][j] < 0 and (j-1>=0 and grid[i][j-1] < 0):
                    j -= 1
                else:
                    return -1
            return j
        
        m, n = len(grid), len(grid[0])
        res = [fall(j) for j in range(n)]

        return res