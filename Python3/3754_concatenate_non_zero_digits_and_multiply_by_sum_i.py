# https://leetcode.cn/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/

class Solution:
    def sumAndMultiply(self, n: int) -> int:
        x, s = 0, 0
        base = 1
        while n > 0:
            value = n % 10
            x += value * base
            s += value
            base *= 10 ** (value > 0)
            n //= 10
        return x * s