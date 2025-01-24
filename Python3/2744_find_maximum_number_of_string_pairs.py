# https://leetcode.cn/problems/find-maximum-number-of-string-pairs/

class Solution:
    def maximumNumberOfStringPairs(self, words):
        """
        Inputs:
            words: list[str]
        Outputs:
            res: int
        """
        res = 0
        s = set()
        for word in words:
            if word[::-1] in s:
                res += 1
            else:
                s.add(word)
        return res