# https://leetcode.cn/problems/lexicographically-smallest-palindrome/

class Solution:
    def makeSmallestPalindrome(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: str
        """
        n = len(s)
        res = [s[i] for i in range(n)]
        for i in range(n//2):
            ch1, ch2 = res[i], res[n-1-i]
            if ch1 != ch2:
                ch = ch1 if ord(ch1) < ord(ch2) else ch2
                res[i] = ch
                res[n-1-i] = ch
        return "".join(res)