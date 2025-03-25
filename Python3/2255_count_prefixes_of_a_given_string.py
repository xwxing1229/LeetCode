# https://leetcode.cn/problems/count-prefixes-of-a-given-string/

class Solution:
    def countPrefixes(self, words, s):
        """
        Inputs:
            words: list[str]
            s: str
        Outputs:
            res: int
        """
        res = 0
        n = len(s)
        for word in words:
            if len(word) <= n and word == s[:len(word)]:
                res += 1
        return res