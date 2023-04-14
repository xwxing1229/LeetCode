# https://leetcode.cn/problems/camelcase-matching/

class Solution:
    def camelMatch(self, queries, pattern):
        """
        Inputs:
            queries: list[str]
            pattern: str
        Outputs:
            res: list[bool]
        """
        n, m = len(queries), len(pattern)
        res = [True for _ in range(n)]
        for i, query in enumerate(queries):
            j = 0
            for ch in query:
                if j < m:
                    if ch == pattern[j]:
                        j += 1
                    elif ch.isupper():
                        res[i] = False
                        break
                else:
                    if ch.isupper():
                        res[i] = False
                        break
            if j < m:
                res[i] = False
        return res