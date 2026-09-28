# https://leetcode.cn/problems/smallest-index-with-digit-sum-equal-to-index/

class Solution:
    def smallestIndex(self, nums: list[int]) -> int:
        for i, num in enumerate(nums):
            n, s = num, 0
            while n > 0:
                s += n % 10
                n //= 10
            if i == s:
                return i
        return -1