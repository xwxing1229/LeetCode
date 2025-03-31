# https://leetcode.cn/problems/percentage-of-letter-in-string/

class Solution:
    def percentageLetter(self, s: str, letter: str) -> int:
        n, cnt = len(s), 0
        for ch in s:
            cnt += ch == letter
        return int(cnt / n * 100)