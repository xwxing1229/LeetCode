# https://leetcode.cn/problems/longest-balanced-substring-i/

from collections import defaultdict

class Solution:
    def longestBalanced(self, s: str) -> int:
        res = 0
        n = len(s)
        for i in range(n):
            cnt = defaultdict(int)
            for j in range(i, n):
                cnt[s[j]] += 1
                value = cnt[s[j]]
                balanced = True
                for v in cnt.values():
                    if value != v:
                        balanced = False
                        break
                if balanced:
                    res = max(res, j-i+1)
        return res