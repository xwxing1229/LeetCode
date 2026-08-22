# https://leetcode.cn/problems/check-divisibility-by-digit-sum-and-product/

class Solution:
    def checkDivisibility(self, n: int) -> bool:
        s, p = 0, 1
        num = n
        while num > 0:
            x = num % 10
            num //= 10
            s += x
            p *= x
        return n % (s + p) == 0