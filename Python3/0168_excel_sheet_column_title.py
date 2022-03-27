# https://leetcode-cn.com/problems/excel-sheet-column-title/

# A, B, C, ..., Z,
# AA, AB, AC, ..., AZ, BA, BB, BC, ...

# If n % 26 = 0, it means that the last string is Z.
# In this case, n = ... + ~*26^1 + 26*26^0, and the
# remainder n // 26 should -1.

# chr(65) = 'A'
# chr(97) = 'a'

class Solution:
    def convertToTitle(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: str
        """
        
        res = ''
        rem = n
        while rem > 0:
            quo = rem % 26
            rem = rem // 26
            if quo == 0:
                res = 'Z' + res
                rem = rem - 1
            else:
                res = chr(64+quo) + res
        return res