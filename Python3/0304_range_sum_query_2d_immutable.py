# https://leetcode.cn/problems/range-sum-query-2d-immutable/

class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        """
        Inputs:
            matrix: list[list[int]]
        Outputs:
            None
        """
        rows = len(matrix)
        cols = len(matrix[0])
        self.sum_to_now = [[0 for col in range(cols)] for row in range(rows)]
        tmp = 0
        for col in range(cols):
            tmp = tmp + matrix[0][col]
            self.sum_to_now[0][col] = tmp
        for row in range(1, rows):
            tmp = 0
            for col in range(cols):
                tmp = tmp + matrix[row][col]
                self.sum_to_now[row][col] = tmp + self.sum_to_now[row-1][col]

    def sumRegion(self, row1, col1, row2, col2):
        """
        Inputs:
            row1, ..., col2: int
        Outputs:
            res: int
        """
        if (row1 == 0) and (col1 == 0):
            return self.sum_to_now[row2][col2]
        elif (row1 == 0) and (col1 != 0):
            return self.sum_to_now[row2][col2] - self.sum_to_now[row2][col1-1]
        elif (row1 != 0) and (col1 == 0):
            return self.sum_to_now[row2][col2] - self.sum_to_now[row1-1][col2]
        else:
            return self.sum_to_now[row2][col2] - self.sum_to_now[row1-1][col2]\
                - self.sum_to_now[row2][col1-1] + self.sum_to_now[row1-1][col1-1]


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)