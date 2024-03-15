#  https://leetcode.cn/problems/maximum-odd-binary-number/

class Solution:
    def maximumOddBinaryNumber(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: str
        """
        cnt1, n = 0, len(s)
        for ch in s:
            if ch == "1":
                cnt1 += 1
        if cnt1 <= 1:
            return "0"*(n-cnt1) + "1"*cnt1
        else:
            return "1"*(cnt1-1) + "0"*(n-cnt1) + "1"