# https://leetcode.cn/problems/count-substrings-that-differ-by-one-character/

class Solution:
    def countSubstrings(self, s, t):
        """
        Inputs:
            s, t: str
        Outputs:
            res: int
        """
        res = 0
        m, n = len(s), len(t)
        for i in range(m):
            for j in range(n):
                diff = 0
                for k in range(min(m-i, n-j)):
                    if s[i+k] != t[j+k]:
                        diff += 1
                    if diff == 1:
                        res += 1
                    elif diff > 1:
                        break
        return res