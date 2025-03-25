# https://leetcode.cn/problems/row-with-maximum-ones/

class Solution:
    def rowAndMaximumOnes(self, mat):
        """
        Inputs:
            mat: list[list[int]]
        Outputs:
            res: list[int]
        """
        res = [0, 0]
        for i, row in enumerate(mat):
            cnt = sum(row)
            if cnt > res[1]:
                res[0] = i
                res[1] = cnt
        return res