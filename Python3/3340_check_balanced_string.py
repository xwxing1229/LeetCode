# https://leetcode.cn/problems/check-balanced-string/

class Solution:
    def isBalanced(self, num: str) -> bool:
        s, k = 0, 1
        for ch in num:
            s += k * int(ch)
            k *= -1
        return s == 0