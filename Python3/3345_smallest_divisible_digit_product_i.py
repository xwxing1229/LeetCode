# https://leetcode.cn/problems/smallest-divisible-digit-product-i/

class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        def valid(num: int) -> bool:
            prod = 1
            while num > 0:
                prod *= (num % 10)
                num //= 10
            return prod % t == 0
        
        num = n
        while num >= n:
            if valid(num):
                return num
            num += 1
        return -1