# https://leetcode-cn.com/problems/pascals-triangle/

class Solution:
    def generate(self, numRows):
        """
        Inputs:
            numRows: int
        Outputs:
            res: list[list[int]]
        """
        
        res = []
        for i in range(numRows):
            if i == 0:
                res.append([1])
            elif i == 1:
                res.append([1,1])
            else:
                row = res[-1]
                newRow = list(range(1,i+2))
                for j in range(1,i):
                    newRow[j] = row[j-1] + row[j]
                newRow[-1] = 1
                res.append(newRow)
        return res