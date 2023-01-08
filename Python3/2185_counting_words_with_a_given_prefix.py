# https://leetcode.cn/problems/counting-words-with-a-given-prefix/

class Solution:
    def prefixCount(self, words, pref):
        """
        Inputs:
            words: list[str]
            pref: str
        Outputs:
            res: int
        """
        res = 0
        n = len(pref)
        for word in words:
            if len(word) >= n and word[:n] == pref:
                res += 1
        return res
