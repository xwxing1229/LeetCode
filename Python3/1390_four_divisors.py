# https://leetcode.cn/problems/four-divisors/

from math import sqrt

class Solution:
    def sumFourDivisors(self, nums: list[int]) -> int:
        res = 0
        for num in nums:
            factor1, factor2 = 0, 0
            for i in range(2, int(sqrt(num))+1):
                j = num // i
                if i * j != num:
                    continue
                elif i == j or factor1 > 0:
                    factor1 = 0
                    break
                else:
                    factor1, factor2 = i, j
            if factor1 != 0:
                res += 1 + num + factor1 + factor2
        return res