# https://leetcode-cn.com/problems/zigzag-conversion/

class Solution:
    def convert(self, s, numRows):
        """
        Inputs:
            s: str
            numRows: int
        Outputs:
            res: str
        """
        
        if numRows == 1:
            return s
        
        tmp =['' for i in range(numRows)]
        
        row = 0
        down = True
        for i in range(len(s)):
            tmp[row] = tmp[row] + s[i]
            if down: # read next row
                row = row + 1
            else: # read last row
                row = row - 1
                
            if row == numRows - 1:
                down = False
            if i > 0 and row == 0:
                down = True
        
        res = ''
        for i in range(numRows):
            res = res + tmp[i]
        return res