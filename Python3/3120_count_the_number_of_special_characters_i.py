# https://leetcode.cn/problems/count-the-number-of-special-characters-i/

class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        res = 0
        s = set(word)
        for i in range(26):
            ch = chr(ord("a") + i)
            res += ch.upper() in s and ch.lower() in s
        return res