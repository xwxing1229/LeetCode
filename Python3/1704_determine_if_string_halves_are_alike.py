# https://leetcode.cn/problems/determine-if-string-halves-are-alike/

class Solution:
    def halvesAreAlike(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: bool
        """
        vowels = "aeiouAEIOU"
        n = len(s)
        cnt = 0
        for i in range(n//2):
            if s[i] in vowels:
                cnt += 1
        for i in range(n//2, n):
            if s[i] in vowels:
                cnt -= 1

        if cnt == 0:
            return True
        else:
            return False