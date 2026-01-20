# https://leetcode.cn/problems/construct-the-minimum-bitwise-array-i/

class Solution:
    def minBitwiseArray(self, nums: list[int]) -> list[int]:
        res = [-1 for _ in range(len(nums))]
        for i, num in enumerate(nums):
            for val in range(1, num):
                if (val | (val+1)) == num:
                    res[i] = val
                    break
        return res