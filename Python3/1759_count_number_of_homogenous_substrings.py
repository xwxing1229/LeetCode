# https://leetcode.cn/problems/count-number-of-homogenous-substrings/

class Solution:
    def countHomogenous(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: int
        """
        res = 0
        cnt = 1
        s += " "
        for i in range(1, len(s)):
            if s[i] == s[i-1]:
                cnt += 1
            else:
                res = (res + (1 + cnt) * cnt // 2) % 1000000007
                cnt = 1
        return res