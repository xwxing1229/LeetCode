# https://leetcode.cn/problems/second-largest-digit-in-a-string/

class Solution:
    def secondHighest(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: int
        """
        res, max_ = -1, -1
        for ch in s:
            if ch.isdigit():
                num = ord(ch) - ord("0")
                if num > max_:
                    res = max_
                    max_ = num
                elif num < max_ and num > res:
                    res = num
        return res