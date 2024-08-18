# https://leetcode.cn/problems/find-missing-and-repeated-values/

class Solution:
    def findMissingAndRepeatedValues(self, grid):
        """
        Inputs:
            grid: list[list[int]]
        Outputs:
            res: list[int]
        """
        n = len(grid)
        check = [0 for _ in range(n*n+1)]
        s = 0
        for row in grid:
            for val in row:
                check[val] += 1
                s += val
        
        res = [0, 0]
        sum2n2 = (1 + n * n) * n * n // 2
        for i in range(1, n*n+1):
            if check[i] == 0:
                res[1] = i
                res[0] = s - sum2n2 + res[1]
                break
            elif check[i] == 2:
                res[0] = i
                res[1] = sum2n2 - s + res[0]
                break
        return res
