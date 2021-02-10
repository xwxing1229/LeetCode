# https://leetcode-cn.com/problems/integer-to-roman/

class Solution:
    def intToRoman(self, num):
        """
        Inputs:
            num: int
        Outputs:
            res: str
        """

        m = {1000: 'M',\
              900: 'CM',\
              500: 'D',\
              400: 'CD',\
              100: 'C',\
               90: 'XC',\
               50: 'L',\
               40: 'XL',\
               10: 'X',\
                9: 'IX',\
                5: 'V',\
                4: 'IV',\
                1: 'I'}

        res = ''
        rem = num
        for i in m:
            quo = rem // i
            rem = rem % i
            res = res + m[i] * quo
        return res