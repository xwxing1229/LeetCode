# https://leetcode.cn/problems/minimum-length-of-string-after-deleting-similar-ends/

class Solution:
    def minimumLength(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: int
        """
        n = len(s)
        l, r = 0, n-1
        while l < r:
            if s[l] != s[r]:
                return r - l + 1
            while l + 1 < n and s[l+1] == s[l]:
                l += 1
            while r - 1 > l and s[r-1] == s[r]:
                r -= 1
            if r == l:
                return 0
            else:
                l += 1
                r -= 1
        return 1