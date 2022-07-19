# https://leetcode.cn/problems/maximal-square/

class Solution:
    def maximalSquare(self, matrix):
        """
        Inputs:
            matrix: list[list[int]]
        Outputs:
            res: int
        """
        
        # Dynamic programming.
        
        res_sqrt = 0
        rows = len(matrix)
        cols = len(matrix[0])
        dp = [0 for _ in range(cols)]
        for col in range(cols):
            if matrix[0][col] == "1":
                dp[col] = 1
                res_sqrt = 1
        for row in range(1, rows):
            last = dp[0]
            if matrix[row][0] == "1":
                dp[0] = 1
            else:
                dp[0] = 0
            res_sqrt = max(res_sqrt, dp[0])
            for col in range(1, cols):
                if matrix[row][col] == "1":
                    tmp = min(last, min(dp[col-1], dp[col])) + 1
                    last = dp[col]
                    dp[col] = tmp
                    res_sqrt = max(res_sqrt, tmp)
                else:
                    dp[col] = 0
        return res_sqrt * res_sqrt