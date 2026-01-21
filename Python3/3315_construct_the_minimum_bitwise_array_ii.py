# https://leetcode.cn/problems/construct-the-minimum-bitwise-array-ii/

class Solution:
    def minBitwiseArray(self, nums: list[int]) -> list[int]:
        res = [-1 for _ in range(len(nums))]
        for i, num in enumerate(nums):
            if num % 2 == 0:
                continue

            k = 0
            while (num >> k) & 1:
                k += 1
            res[i] = num ^ (1 << (k-1))
        return res