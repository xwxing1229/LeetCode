# https://leetcode.cn/problems/smallest-missing-non-negative-integer-after-operations/

class Solution:
    def findSmallestInteger(self, nums, value):
        """
        Inputs:
            nums: list[int]
            value: int
        Outputs:
            res: int
        """
        remainder = [0 for _ in range(value)]
        for num in nums:
            remainder[(num % value + value) % value] += 1
        res = 0
        while remainder[res % value] > 0:
            remainder[res % value] -= 1
            res += 1
        return res