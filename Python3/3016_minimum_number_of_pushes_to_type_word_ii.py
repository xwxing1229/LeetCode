# https://leetcode.cn/problems/minimum-number-of-pushes-to-type-word-ii/

class Solution:
    def minimumPushes(self, word: str) -> int:
        ord_a = ord("a")
        count = [0 for _ in range(26)]
        for ch in word:
            count[ord(ch) - ord_a] += 1
        count.sort(reverse=True)

        res = 0
        for i, cnt in enumerate(count):
            res += (i // 8 + 1) * cnt
        return res