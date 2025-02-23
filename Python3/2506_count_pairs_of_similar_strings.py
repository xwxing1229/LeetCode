# https://leetcode.cn/problems/count-pairs-of-similar-strings/

from collections import defaultdict

class Solution:
    def similarPairs(self, words) -> int:
        """
        Inputs:
            words: list[str]
        Outputs:
            res: int
        """
        res = 0
        cnts = defaultdict(int)
        ord_a = ord("a")
        for word in words:
            val = 0
            for ch in word:
                val |= (1 << (ord(ch) - ord_a))
            res += cnts[val]
            cnts[val] += 1
        return res