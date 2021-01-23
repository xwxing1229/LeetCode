# https://leetcode-cn.com/problems/pascals-triangle-ii/

class Solution:
    def getRow(self, rowIndex):
        """
        Inputs:
            rowIndex: int
        Outputs:
            res: list[int]
        """
        
        res = [1]
        for i in range(1,rowIndex+1):
            res.insert(0,0)
            for j in range(i):
                res[j] = res[j] + res[j+1]
        return res