# https://leetcode-cn.com/problems/to-lower-case/

# ord('A') = 65, ord('a') = 97
# chr(65) = 'A', chr(97) = 'a'

class Solution:
    def toLowerCase(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: str
        """
        
        res = ''
        for i in s:
            tmp = ord(i)
            if tmp <= 90 and tmp >= 65:
                res = res + chr(tmp + 32)
            else:
                res = res + i
        return res