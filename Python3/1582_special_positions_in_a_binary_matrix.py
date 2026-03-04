# https://leetcode.cn/problems/special-positions-in-a-binary-matrix/

class Solution:
    def numSpecial(self, mat: list[list[int]]) -> int:
        m, n = len(mat), len(mat[0])
        rec_row = [[] for _ in range(m)]
        rec_col = [[] for _ in range(n)]
        for i, row in enumerate(mat):
            for j, num in enumerate(row):
                if num == 1:
                    rec_row[i].append(j)
                    rec_col[j].append(i)
        res = 0
        for rec in rec_row:
            if len(rec) == 0 or len(rec) > 1:
                continue
            elif len(rec_col[rec[0]]) == 1:
                res += 1
        return res