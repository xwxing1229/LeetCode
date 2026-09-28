# https://leetcode.cn/problems/evaluate-the-bracket-pairs-of-a-string/

from collections import defaultdict
class Solution:
    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:
        d = defaultdict(lambda: "?", knowledge)
        res = ""
        i, n = 0, len(s)
        while i < n:
            if s[i] == "(":
                prev = i
                while i < n and s[i] != ")":
                    i += 1
                res += d[s[prev+1: i]]
            else:
                res += s[i]
            i += 1
        return res