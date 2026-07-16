# https://leetcode.cn/problems/sum-of-gcd-of-formed-pairs/

from math import gcd

class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        n = len(nums)
        mx = nums[0]
        prefixGcd = [0 for _ in range(n)]
        for i, num in enumerate(nums):
            mx = max(mx, num)
            prefixGcd[i] = gcd(mx, num)
        prefixGcd.sort()

        res = 0
        for i in range(n//2):
            res += gcd(prefixGcd[i], prefixGcd[n-1-i])
        return res