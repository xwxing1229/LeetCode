# https://leetcode.cn/problems/minimum-number-of-pushes-to-type-word-i/

class Solution:
    def minimumPushes(self, word: str) -> int:
        n = len(word)
        k, rem = n // 8, n % 8
        return (4 * k + rem) * (k + 1)