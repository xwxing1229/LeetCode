# https://leetcode.cn/problems/champagne-tower/

class Solution:
    def champagneTower(self, poured, query_row, query_glass):
        """
        Inputs:
            poured: int
            query_row: int
            query_glass: int
        Outputs:
            res: float
        """

        # Simulate the process.
        row = [0 for i in range(query_row+1)]
        row[0] = poured
        overflow, overflow_pre = 0, 0
        for i in range(query_row):
            for j in range(i+1):
                if row[j] > 1:
                    overflow = (row[j] - 1) / 2
                else:
                    overflow = 0
                row[j] = overflow
                if j > 0:
                    row[j] += overflow_pre
                overflow_pre = overflow
                    
            row[i+1] = overflow
            
        return min(row[query_glass], 1)
