# https://leetcode.cn/problems/maximum-score-from-removing-stones/

class Solution:
    def maximumScore(self, a, b, c):
        """
        Inputs:
            a, b, c: int
        Outputs:
            res: int
        """
        s = a + b + c
        max_ = max(a, b, c)
        if s <= max_ + max_:
            res = s - max_
        else:
            res = (s - max_ - max_) // 2 + max_
        return res
