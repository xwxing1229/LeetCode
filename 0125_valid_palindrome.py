# https://leetcode-cn.com/problems/valid-palindrome/

class Solution:
    def isPalindrome(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: bool
        """
        
        i = 0
        j = len(s) - 1
        res = True
        while i < j:
            while (i < len(s)) and (not s[i].isalnum()):
                i = i + 1
            while (j > -1) and (not s[j].isalnum()):
                j = j - 1
            
            if i == len(s):
                break
            if s[i].lower() != s[j].lower():
                res = False
                break
            else:
                i = i + 1
                j = j - 1
        return res