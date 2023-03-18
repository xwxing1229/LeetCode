# https://leetcode.cn/problems/split-two-strings-to-make-palindrome/

class Solution:
    def checkPalindromeFormation(self, a, b):
        """
        Inputs:
            a, b: str
        Outputs:
            res: bool
        """
        if self.isPalindrome(a) or self.isPalindrome(b):
            return True
        
        n = len(a)
        flag1, flag2 = True, True
        for i in range(1, n//2+1):
            if a[i-1] != b[n-i]:
                flag1 = False
            if b[i-1] != a[n-i]:
                flag2 = False
            if not (flag1 or flag2):
                sub1 = a[i-1: n-i+1]
                sub2 = b[i-1: n-i+1]
                if self.isPalindrome(sub1) or self.isPalindrome(sub2):
                    return True
                else:
                    return False
        if flag1 or flag2:
            return True
        else:
            return False
    
    def isPalindrome(self, s):
        i, j = 0, len(s) - 1
        while i <= j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True