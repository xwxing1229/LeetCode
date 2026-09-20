# https://leetcode.cn/problems/reverse-degree-of-a-string/

class Solution:
    def reverseDegree(self, s: str) -> int:
        res = 0
        ord_a = ord("a")
        for i, ch in enumerate(s):
            x = 26 - (ord(ch) - ord_a)
            res += x * (i + 1)
        return res