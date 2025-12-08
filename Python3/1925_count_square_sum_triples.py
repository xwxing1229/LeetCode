# https://leetcode.cn/problems/count-square-sum-triples/

import math

class Solution:
    def countTriples(self, n: int) -> int:
        res = 0
        n_sq = n * n
        for a in range(1, int(n/1.4)+1):
            a_sq = a * a
            for b in range(a+1, n+1):
                s = a_sq + b * b
                if s > n_sq:
                    break
                s_sqrt = int(math.sqrt(s))
                res += (s_sqrt * s_sqrt == s)
        res *= 2
        return res