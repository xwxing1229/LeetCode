# https://leetcode.cn/problems/make-a-square-with-the-same-color/

class Solution:
    def canMakeSquare(self, grid):
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: bool
        """
        for i in range(2):
            for j in range(2):
                cnt = 0
                if grid[i][j] == "W":
                    cnt += 1
                if grid[i][j+1] == "W":
                    cnt += 1
                if grid[i+1][j] == "W":
                    cnt += 1
                if grid[i+1][j+1] == "W":
                    cnt += 1
                if cnt != 2:
                    return True
        return False