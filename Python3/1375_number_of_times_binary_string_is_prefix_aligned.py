# https://leetcode.cn/problems/number-of-times-binary-string-is-prefix-aligned/

class Solution:
    def numTimesAllBlue(self, flips):
        """
        Inputs:
            flips: list[int]
        Outputs:
            res: int
        """
        res, max_ = 0, 0
        for i, flip in enumerate(flips):
            if max_ < flip:
                max_ = flip
            if i + 1 == max_:
                res += 1
        return res