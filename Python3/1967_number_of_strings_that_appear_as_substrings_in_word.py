# https://leetcode.cn/problems/number-of-strings-that-appear-as-substrings-in-word/

class Solution:
    def numOfStrings(self, patterns: list[str], word: str) -> int:
        res = 0
        for p in patterns:
            res += p in word
        return res