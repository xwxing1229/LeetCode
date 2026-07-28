# https://leetcode.cn/problems/smallest-palindromic-rearrangement-i/

class Solution:
    def smallestPalindrome(self, s: str) -> str:
        n = len(s)
        ord_a = ord("a")
        count = [0 for _ in range(26)]
        for i in range(n//2):
            count[ord(s[i]) - ord_a] += 1

        res = ""
        for i, cnt in enumerate(count):
            res += chr(ord_a + i) * cnt
        res = res + s[n//2] * (n%2) + res[::-1]
        return res