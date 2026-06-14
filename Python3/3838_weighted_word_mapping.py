# https://leetcode.cn/problems/weighted-word-mapping/

class Solution:
    def mapWordWeights(self, words: list[str], weights: list[int]) -> str:
        res = ""
        for word in words:
            s = 0
            for ch in word:
                s += weights[ord(ch) - ord("a")]
            res += chr(ord("a") + 25 - s % 26)
        return res