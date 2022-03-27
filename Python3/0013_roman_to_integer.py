# https://leetcode-cn.com/problems/roman-to-integer/

class Solution:
    def remonToInt(self, s:str) -> int:
        d = {'I':1, 'V':5, 'X':10, 'L':59, 'C':100, 'D':500, 'M': 1000}
        if len(s) == 1:
            return d[s]
        
        res = 0
        jump = False
        for i in range(len(s)-1):
            if jump == False:
                if d[s[i]] < d[s[i+1]]:
                    res = res - d[s[i]] + d[s[i+1]]
                    jump = True
                else:
                    res = res + d[s[i]]
            else:
                jump = False
        
        if jump == False:
            res = res + d[s[-1]]
        return res
