# https://leetcode.cn/problems/maximum-matrix-sum/

class Solution:
    def maxMatrixSum(self, matrix: list[list[int]]) -> int:
        res = 0
        neg_cnt = 0
        abs_min = -1
        for row in matrix:
            for val in row:
                if val < 0:
                    neg_cnt += 1
                    val = -val
                res += val
                if abs_min < 0 or abs_min >= val:
                    abs_min = val
        if neg_cnt % 2:
            res -= 2 * abs_min
        return res