# https://leetcode.cn/problems/increment-submatrices-by-one/

class Solution:
    def rangeAddQueries(self, n: int, queries):
        """
        Inputs:
            n: int
            queries: list[list[int]]
        Outputs:
            res: list[list[int]]
        """
        diff = [[0 for _ in range(n+1)] for _ in range(n+1)]
        for q in queries:
            i1, j1, i2, j2 = q[0], q[1], q[2], q[3]
            diff[i1][j1] += 1
            diff[i2+1][j1] -= 1
            diff[i1][j2+1] -= 1
            diff[i2+1][j2+1] += 1
        for i in range(n):
            for j in range(1, n):
                diff[i][j] += diff[i][j-1]
        for i in range(1, n):
            for j in range(n):
                diff[i][j] += diff[i-1][j]

        res = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(n):
            for j in range(n):
                res[i][j] = diff[i][j]
        return res