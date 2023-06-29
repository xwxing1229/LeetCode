# https://leetcode.cn/problems/reconstruct-a-2-row-binary-matrix/

class Solution:
    def reconstructMatrix(self, upper, lower, colsum):
        """
        Inputs:
            upper, lower: int
            colsum: list[int]
        Outputs:
            res: list[list[int]]
        """
        n = len(colsum)
        res = [[0 for j in range(n)] for i in range(2)]
        for j, s in enumerate(colsum):
            if s == 2:
                if upper > 0 and lower > 0:
                    res[0][j] = 1
                    res[1][j] = 1
                    upper -= 1
                    lower -= 1
                else:
                    return []
        for j, s in enumerate(colsum):
            if s == 1:
                if upper > 0:
                    res[0][j] = 1
                    upper -= 1
                elif lower > 0:
                    res[1][j] = 1
                    lower -= 1
                else:
                    return []
        if upper != 0 or lower != 0:
            return []
        return res