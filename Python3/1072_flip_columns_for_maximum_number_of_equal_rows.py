# https://leetcode.cn/problems/flip-columns-for-maximum-number-of-equal-rows/

class Solution:
    def maxEqualRowsAfterFlips(self, matrix):
        """
        Inputs:
            matrix: List[List[int]]
        Outputs:
            res: int
        """
        rows, cols = len(matrix), len(matrix[0])
        cnt = defaultdict(int)
        for row in range(rows):
            s = ""
            for col in range(cols):
                if matrix[row][0] == 0:
                    s += str(matrix[row][col])
                else:
                    s += str(1 - matrix[row][col])
            cnt[s] += 1
        res = 0
        for k, v in cnt.items():
            if v > res:
                res = v
        return res