# https://leetcode.cn/problems/is-subsequence/

class Solution:
    def isSubsequence(self, s, t):
        """
        Inputs:
            s: str
            t: str
        Outputs:
            res: bool
        """

        k = 0
        n = len(t)
        for ch in s:
            while (k < n) and (ch != t[k]):
                k = k + 1
            if k >= n:
                return False

            k = k + 1
        return True