# https://leetcode.cn/problems/check-if-binary-string-has-at-most-one-segment-of-ones/

class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        n, i = len(s), 0
        while i < n and s[i] == "1":
            i += 1
        j = i
        while j < n and s[j] == "0":
            j += 1
        return j == n