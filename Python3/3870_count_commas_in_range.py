# https://leetcode.cn/problems/count-commas-in-range/

class Solution:
    def countCommas(self, n: int) -> int:
        digits, num = 0, n
        while num > 0:
            num //= 10
            digits += 1
        res = 0
        left = 1000
        for _ in range(4, digits+1):
            right = min(left * 10 - 1, n)
            res += right - left + 1
            left *= 10
        return res