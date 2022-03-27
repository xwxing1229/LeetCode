# https://leetcode-cn.com/problems/excel-sheet-column-number/

# ord('A') = 65
# ord('a') = 97

class Solution:
    def titleToNumber(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: int
        """
        
        res = 0
        for i in s:
            res = res * 26 + ord(i) - 64
        return res