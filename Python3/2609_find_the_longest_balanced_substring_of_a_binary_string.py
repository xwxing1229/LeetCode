# https://leetcode.cn/problems/find-the-longest-balanced-substring-of-a-binary-string/

class Solution:
    def findTheLongestBalancedSubstring(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: int
        """
        res = 0
        start0, i, n = 0, 0, len(s)
        while i < n:
            while i < n and s[i] != "1":
                i += 1
            if i >= n:
                break

            zeros = i - start0
            start1 = i
            while i < n and s[i] != "0":
                i += 1
            res = max(res, 2*min(zeros, i-start1))
            start0 = i
        return res