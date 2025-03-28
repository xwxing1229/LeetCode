# https://leetcode.cn/problems/minimize-string-length/

class Solution:
    def minimizedStringLength(self, s: str) -> int:
        check = [0 for _ in range(26)]
        ord_a = ord("a")
        for ch in s:
            check[ord(ch) - ord_a] = 1
        return sum(check)