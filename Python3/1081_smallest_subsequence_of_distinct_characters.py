# https://leetcode.cn/problems/smallest-subsequence-of-distinct-characters/

from collections import Counter

class Solution:
    def smallestSubsequence(self, s: str) -> str:
        cnt = Counter(s)
        res = []
        has = set()
        for ch in s:
            cnt[ch] -= 1
            if ch in has:
                continue
            while res and ch < res[-1] and cnt[res[-1]]:
                has.remove(res.pop())
            res.append(ch)
            has.add(ch)
        return "".join(res)