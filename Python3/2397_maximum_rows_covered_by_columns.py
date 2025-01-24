# https://leetcode.cn/problems/maximum-rows-covered-by-columns/

class Solution:
    def maximumRows(self, matrix, numSelect):
        """
        Inputs:
            matrix: list[list[int]]
            numSelect: int
        Outputs:
            res: int
        """
        self.matrix = matrix
        self.res = 0
        cols = set()
        self.dfs(0, numSelect, cols)
        return self.res

    def dfs(self, idx, numSelect, cols:set):
        m, n = len(self.matrix), len(self.matrix[0])
        if numSelect == 0:
            tmp = 0
            for row in range(m):
                tmp += 1
                for col in range(n):
                    if col not in cols and self.matrix[row][col] == 1:
                        tmp -= 1
                        break
            self.res = max(self.res, tmp)
        
        for col in range(idx, n):
            cols.add(col)
            self.dfs(col+1, numSelect-1, cols)
            cols.remove(col)